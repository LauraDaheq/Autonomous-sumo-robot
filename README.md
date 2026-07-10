# 🤖 Autonomous Sumo Robot

An autonomous sumo robot developed using **Arduino** for robotics competitions. The robot is designed to detect opponents with ultrasonic sensors while preventing itself from leaving the arena using infrared line sensors.

This project demonstrates embedded systems programming, sensor integration, motor control, and autonomous decision-making in a real-world robotics application.

---

## 📖 Overview

The robot continuously monitors its surroundings and executes the following strategy:

1. Detect the arena boundary using infrared sensors.
2. If the edge is detected, immediately retreat and change direction.
3. Search for an opponent using front ultrasonic sensors.
4. Attack the opponent when it is within range.
5. Continue searching if no opponent is detected.

This priority-based behavior allows the robot to remain inside the ring while actively engaging opponents.

---

## ✨ Features

- Autonomous navigation
- Opponent detection using ultrasonic sensors
- Arena edge detection using infrared sensors
- Differential drive motor control
- Autonomous attack strategy
- Real-time sensor processing
- Embedded C++ programming with Arduino

---

## 🛠 Hardware

| Component | Description |
|-----------|-------------|
| Arduino Uno | Main microcontroller |
| HC-SR04 Ultrasonic Sensors | Opponent detection |
| Infrared Line Sensors | Arena edge detection |
| L298N Motor Driver | DC motor control |
| DC Gear Motors | Robot locomotion |
| LiPo Battery | Power supply |

---

## 💻 Software

- Arduino IDE
- Arduino C++
- Embedded Systems Programming

---

## ⚙ Robot Strategy

The control algorithm follows a simple priority-based decision process.

```text
Start
   │
   ▼
Read IR Sensors
   │
Edge detected?
   │
 ├── Yes
 │      │
 │      ▼
 │ Reverse
 │ Turn
 │
 └── No
        │
        ▼
Read Ultrasonic Sensors
        │
Opponent detected?
        │
 ├── Yes
 │      │
 │      ▼
 │ Attack
 │
 └── No
        │
        ▼
Search by Rotating
```

---

## 📂 Repository Structure

```
autonomous-sumo-robot
│
├── src
│   └── SumoArduino.ino
│
├── images
│
├── docs
│
├── LICENSE
│
└── README.md
```

---

## 📌 Pin Configuration

### Ultrasonic Sensors

| Sensor | Trigger | Echo |
|---------|--------:|-----:|
| Front Left | 2 | 3 |
| Front Right | 4 | 5 |
| Rear Left | 6 | 7 |
| Rear Right | 8 | 9 |

### Infrared Sensors

| Sensor | Pin |
|---------|----:|
| IR1 | 10 |
| IR2 | 11 |
| IR3 | 12 |
| IR4 | 13 |

### Motor Driver (L298N)

| Signal | Pin |
|---------|----:|
| IN1 | A0 |
| IN2 | A1 |
| IN3 | A2 |
| IN4 | A3 |
| ENA | A4 |
| ENB | A5 |

---

## 🧠 Control Logic

The robot prioritizes safety over attack.

1. Detect arena boundaries.
2. Reverse immediately if the edge is detected.
3. Rotate to reposition safely.
4. Scan for opponents.
5. Move forward aggressively when an opponent is detected.

This behavior ensures the robot remains inside the competition arena while maximizing offensive opportunities.

---

## 🚀 Skills Demonstrated

- Embedded Systems
- Arduino Programming
- C++
- Robotics
- Autonomous Navigation
- Sensor Integration
- Ultrasonic Sensors
- Infrared Sensors
- Motor Control
- Decision Algorithms
- Hardware Integration
- Real-Time Programming

---

## 🔮 Future Improvements

- PID motor control
- Sensor fusion
- State machine implementation
- IMU integration
- Adjustable parameters through configuration
- Modular code architecture
- Improved opponent tracking

---

## 📸 Images

You can place photos of the robot inside the `images/` folder.

Example:

```
images/
├── robot.jpg
├── competition.jpg
└── arena.jpg
```

---

## 📜 License

This project is released under the MIT License.

---

## 👩‍💻 Author

**Laura Daniela Hernandez Ramos**

Electronic Engineer

- GitHub: https://github.com/LauraDaheq
- LinkedIn: https://www.linkedin.com/in/laura-daniela-hernandez-ramos-891482311/

---

## ⭐ About

This project was developed as part of a robotics competition to design and program an autonomous sumo robot capable of detecting opponents, avoiding arena boundaries, and making real-time decisions using embedded systems.
