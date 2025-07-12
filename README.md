# 🧤 Immersive VR Game with Glove-Based Input Integration

Demonstrated the functionality of a custom VR glove integrated with an Unreal Engine game through a real-time testing video. The project highlights glove-based input detection, gesture responsiveness, and immersive gameplay mechanics. This video showcases the successful interaction between hardware and software, emphasizing smooth tracking, in-game feedback, and user control precision in a virtual environment.

## 🧠 Project Summary

- **Engine:** Unreal Engine (Blueprints & C++)
- **Microcontroller:** ESP32 (WiFi-enabled)
- **Sensors:**  
  - MPU-9250 (9-axis IMU: gyroscope, accelerometer, magnetometer)  
  - Flex sensors (for finger bending detection)
- **Communication:** Wireless UDP over WiFi (ESP32 → Unreal)

## ✋ Glove-Based Interaction Features

- **9-DOF Hand Orientation Tracking**  
  Real-time tracking of hand rotation (pitch, roll, yaw) using the MPU-9250.

- **Finger Flex Detection**  
  Flex sensors placed on glove fingers detect bend degree and map to virtual hand actions (e.g., grabbing, pointing, punching).

- **Wireless Data Transmission**  
  Sensor data is transmitted over WiFi using **UDP protocol**, reducing latency and enhancing mobility.

- **Immersive VR Gameplay**  
  Players interact with objects and the game world using natural hand gestures and movements, enhancing realism.

## 🔧 Technologies Used

- Unreal Engine (VR, Blueprints, C++)
- ESP32 Microcontroller (WiFi)
- MPU-9250 Sensor
- Flex Sensors (5 total, one per finger)
- UDP Communication (ESP32 → PC)
- Signal Processing & Calibration (on ESP32)

## ⚙️ System Workflow

1. **Sensor Glove Input:**  
   - MPU-9250 tracks orientation of the hand.  
   - Flex sensors measure finger bend angles.

2. **ESP32 Processing:**  
   - Reads sensor values and formats data.  
   - Sends packets over WiFi via UDP to the host computer.

3. **Unreal Engine Integration:**  
   - Listens for UDP packets in real-time.  
   - Maps sensor data to virtual hand model and in-game interactions.

## 📸 Screenshots & Media

### 🧤 Glove Hardware
![Glove ]([docs/images/glove_setup.jpg](https://github.com/abdalla20736/VR-Gloves-With-Unreal-Engine-Application/assets/55684848/cca43621-73fc-4c31-94de-339744a04dd2))

### 🎮 In-Game
![VR Hand in Unreal Engine]([docs/images/hand_tracking.jpg](https://github.com/abdalla20736/VR-Gloves-With-Unreal-Engine-Application/assets/55684848/3b800d79-7623-4e1c-bb57-5a2be8be6da4))

## 📁 Folder Structure
/UnrealProject ### Unreal Engine project files
/ESP32_Code ### Arduino IDE code for ESP32




