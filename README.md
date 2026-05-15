# 🚆Railway-Inspection-System-Using-IoT

<p align="center">
  <img src="images/logo.png" alt="Project Logo" width="180"/>
</p>

<p align="center">
  <b>An IoT-based smart railway inspection system for real-time track monitoring, hazard detection, and remote surveillance.</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-IoT-blue" />
  <img src="https://img.shields.io/badge/Firebase-Realtime%20Database-orange" />
  <img src="https://img.shields.io/badge/Arduino-IDE-green" />
  <img src="https://img.shields.io/badge/IoT-Smart%20Monitoring-purple" />
</p>

---

##  Overview

Railway safety is a critical concern due to track defects, obstacles, fire hazards, water accumulation, and track misalignment. This project presents an **IoT-enabled Railway Inspection System** designed to automate railway track monitoring using a smart robotic inspection vehicle.

The system uses an **ESP32 microcontroller** integrated with multiple sensors to detect abnormalities in real time. Sensor data is transmitted wirelessly to a mobile application for continuous monitoring, allowing quick decision-making and preventive maintenance.

This solution reduces dependence on manual inspection while improving railway safety, operational efficiency, and real-time fault reporting.

---

##  Key Features

-  Real-time railway track monitoring
-  IoT-based wireless data transmission
-  Fire hazard detection
-  Water leakage/flood detection
-  Obstacle detection using ultrasonic sensors
-  Track tilt/misalignment detection
-  Mobile app live monitoring dashboard
-  Remote movement control
-  Automated fault detection and alerts
-  Smart robotic inspection prototype

---

##  Hardware Components

| Component | Quantity | Purpose |
|---------|---------|---------|
| ESP32 Development Board | 1 | Main controller with Wi-Fi connectivity |
| Ultrasonic Sensor (HC-SR04) | 2 | Obstacle detection |
| IR Sensor | 2 | Crack/object detection |
| Tilt Sensor | 1 | Track misalignment detection |
| Flame Sensor | 1 | Fire hazard detection |
| Water Sensor | 1 | Water leakage/flood detection |
| L298N Motor Driver | 1 | Motor control |
| DC Motors | 2 | Robot movement |
| Robot Chassis | 1 | Prototype base |
| Battery Pack | 1 | Power supply |
| Breadboard & Jumper Wires | Multiple | Circuit connections |

---

##  Software & Technologies Used

| Technology | Purpose |
|----------|---------|
| Arduino IDE | ESP32 programming |
| Embedded C/C++ | Firmware development |
| Firebase Realtime Database | Cloud data storage |
| Android App | Live monitoring and control |
| IoT | Wireless communication |
| Wi-Fi | Data transmission |

---

##  System Architecture

<p align="center">
  <img src="images/system_architecture.png" alt="System Architecture" width="800"/>
</p>

### Architecture Description

The system architecture consists of:

- **ESP32 Controller** as the central processing unit
- Multiple sensors for hazard detection
- Motor driver for robotic movement control
- Cloud communication for remote monitoring
- Mobile application interface for live data visualization and control

---

##  Circuit Diagram

<p align="center">
  <img src="images/circuit_diagram.png" alt="Circuit Diagram" width="900"/>
</p>

### Circuit Description

The circuit integrates the ESP32 microcontroller with:

- Ultrasonic sensors for obstacle detection
- IR sensors for object/crack monitoring
- Flame sensor for fire detection
- Water sensor for leakage monitoring
- Tilt sensor for track angle monitoring
- L298N motor driver for DC motor operation

---

##  Mobile App Interface

<p align="center">
  <img src="images/app_interface.png" alt="App Interface" width="300"/>
</p>

### App Features

The Android monitoring application provides:

- Live fire detection status
- Water detection monitoring
- Obstacle status updates
- Track tilt status indication
- Manual directional movement control
- Emergency stop functionality

---

##  Prototype Implementation

<p align="center">
  <img src="images/prototype.jpg" alt="Prototype" width="500"/>
</p>

The working hardware prototype demonstrates the real-time implementation of the railway inspection robot with integrated sensors, motor control, and wireless communication.

---

##  Working Principle

### Step 1: Sensor Monitoring
The robot continuously collects real-time data from:

- Ultrasonic sensors
- IR sensors
- Tilt sensor
- Flame sensor
- Water sensor

### Step 2: Data Processing
The ESP32 processes incoming sensor data and determines whether abnormal conditions exist.

### Step 3: Hazard Detection
If any hazard is detected, such as:

- Fire
- Water accumulation
- Track tilt
- Obstacle ahead

the system identifies the issue immediately.

### Step 4: Wireless Data Transmission
Sensor data is transmitted via Wi-Fi to Firebase for remote monitoring.

### Step 5: Mobile Monitoring
Users can monitor the system status in real time using the Android application.

### Step 6: Movement Control
The robot movement is controlled using the L298N motor driver and can be manually operated via the mobile interface.

---

##  Results

The implemented system successfully demonstrated:

- Real-time hazard monitoring  
- Wireless remote monitoring  
- Live mobile dashboard updates  
- Obstacle detection accuracy  
- Water and fire hazard identification  
- Track tilt monitoring  
- Remote robotic movement control  

---

##  Applications

- Railway track inspection
- Preventive railway maintenance
- Smart transportation monitoring
- Disaster hazard monitoring
- Automated safety surveillance
- Remote inspection systems

---

##  Advantages

- Reduces manual inspection effort
- Improves railway safety
- Enables early fault detection
- Provides real-time monitoring
- Cost-effective prototype solution
- Supports remote access
- Scalable for smart railway systems

---

##  Future Improvements

Possible future enhancements:

- AI-based crack detection using computer vision
- GPS-based exact fault location tracking
- GSM/SMS emergency alert system
- Autonomous navigation using AI
- Cloud analytics dashboard
- Integration with railway control infrastructure
- Predictive maintenance using machine learning

---

##  Project Structure

```bash
Railway-Inspection-System-Using-IoT/
│
├── README.md
├── code/
│   └── railway_inspection.ino
├── images/
│   ├── logo.png
│   ├── circuit_diagram.png
│   ├── system_architecture.png
│   ├── app_interface.png
│   └── prototype.jpg
└── LICENSE
