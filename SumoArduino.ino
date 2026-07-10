// Pines de sensores ultrasónicos
#define TRIG1 2
#define ECHO1 3
#define TRIG2 4
#define ECHO2 5
#define TRIG3 6
#define ECHO3 7
#define TRIG4 8
#define ECHO4 9

// Pines de sensores infrarrojos
#define IR1 10
#define IR2 11
#define IR3 12
#define IR4 13

// Pines del puente H (L298N)
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
#define ENA A4  // PWM Motor 1
#define ENB A5  // PWM Motor 2

// Velocidad de los motores (0-255)
#define VELOCIDAD 130

void setup() {
    Serial.begin(9600);
    pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
    pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
    pinMode(TRIG4, OUTPUT); pinMode(ECHO4, INPUT);
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    pinMode(IR3, INPUT);
    pinMode(IR4, INPUT);
    pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
}

long medirDistancia(int trig, int echo) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    return pulseIn(echo, HIGH) * 0.034 / 2; // Convertir a cm
}
void moverAdelante() {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Motor A adelante
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Motor B adelante
    analogWrite(ENA, VELOCIDAD);
    analogWrite(ENB, VELOCIDAD);
}

void retroceder() {
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);  // Motor A atrás
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);  // Motor B atrás
    analogWrite(ENA, VELOCIDAD);
    analogWrite(ENB, VELOCIDAD);
}

void girarIzquierda() {
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);  // Motor A atrás
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Motor B adelante
    analogWrite(ENA, VELOCIDAD);
    analogWrite(ENB, VELOCIDAD);
}

void girarDerecha() {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Motor A adelante
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);  // Motor B atrás
    analogWrite(ENA, VELOCIDAD);
    analogWrite(ENB, VELOCIDAD);
}

void detenerMotores() {
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}


void loop() {
    // Leer sensores IR (1: detecta línea blanca, 0: piso oscuro)
    bool linea_izq = digitalRead(IR3);
    bool linea_der = digitalRead(IR1);
    bool linea_arriba = digitalRead(IR4);
    bool linea_abajo = digitalRead(IR2);
    
    Serial.print("der: ");
    Serial.println(linea_der); // print the value and go to the next line

    Serial.print("izq: ");
    Serial.println(linea_izq); // print the value and go to the next line

    Serial.print("arriba: ");
    Serial.println(linea_arriba); // print the value and go to the next line

    Serial.print("abajo: ");
    Serial.println(linea_abajo);// print the value and go to the next line

    delay(500); // wait for half a second
    
    // Si detecta línea blanca, retrocede y gira
// Si detecta línea blanca, retrocede y gira
if (!linea_izq) {
    retroceder();
    delay(300);
    girarDerecha(); // Puedes ajustar si prefieres otro giro
    delay(300);
    Serial.println("entreIzq");
} else if (!linea_der) {
    retroceder();
    delay(300);
    girarIzquierda();
    delay(300);
    Serial.println("entreDer");
} else {
    // Detectar al oponente solo con sensores frontales
    long d1 = medirDistancia(TRIG1, ECHO1);
    long d2 = medirDistancia(TRIG2, ECHO2);

    Serial.print("d1: ");
    Serial.println(d1);
    Serial.print("d2: ");
    Serial.println(d2);
    Serial.println(" ");

    if (d1 < 30 || d2 < 30) {
        moverAdelante(); // Atacar al oponente si está al frente
    } else if (d1 < d2) {
        girarIzquierda(); // Ajuste si está más hacia el lado izquierdo
    } else if (d2 < d1) {
        girarDerecha(); // Ajuste si está más hacia el lado derecho
    } else {
        detenerMotores(); // No hay oponente, quedarse quieto
    }
 }

}
