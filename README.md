# Gesture-Controlled Robot Car

This project implements a wireless gesture-controlled robotic car using an Arduino Nano, ADXL335 accelerometer, and nRF24L01 RF modules. The system allows intuitive and real-time control of the robot using hand gestures, making it suitable for applications in education, automation, and defense.

## Abstract

The restricted use and accessibility of gesture-controlled robot cars is a robotics challenge. Current solutions often lack intuitive interfaces and adaptability. This project proposes an adaptive, intuitive gesture-controlled system that uses accelerometer input and wireless communication to control a robot. The system leverages Arduino programming and RF modules to interpret hand gestures and control the car accordingly.

## Features

- Hand gesture control using ADXL335
- Wireless communication using nRF24L01
- Motor control via L298N driver
- Real-time gesture-to-motion response
- Compact design with Arduino Nano

## Project Structure

```
Gesture-Controlled-Robot-Car/
├── transmitter/
│   └── gesture_transmitter.ino
├── receiver/
│   └── gesture_receiver.ino
├── images/
│   ├── arduino_files.png
│   └── system_ui.png
├── README.md
```

## Hardware Components

| Component           | Description                                       |
|--------------------|---------------------------------------------------|
| Arduino Nano        | Microcontroller board for both TX and RX         |
| ADXL335             | 3-axis analog accelerometer                       |
| nRF24L01            | 2.4GHz RF transceiver for wireless communication |
| L298N Motor Driver  | Controls two DC motors                           |
| DC Motors           | Drive movement of the robot                      |
| Power Supply        | Battery to power the system                      |

## Transmitter Code (`gesture_transmitter.ino`)

- Reads analog values from X and Y axes of ADXL335
- Sends data over RF using nRF24L01 module
- Sample loop delay of 1 second for stability

## Receiver Code (`gesture_receiver.ino`)

- Receives data from transmitter
- Interprets gesture based on X and Y values
- Controls motor direction via L298N motor driver

## How to Run

1. Connect the **transmitter components** (Arduino Nano, ADXL335, nRF24L01).
2. Upload `gesture_transmitter.ino` to the transmitter board.
3. Connect the **receiver components** (Arduino Nano, L298N, DC motors, nRF24L01).
4. Upload `gesture_receiver.ino` to the receiver board.
5. Power both boards and test with simple hand tilts:
   - Forward Tilt → Move Forward
   - Backward Tilt → Move Backward
   - Left Tilt → Turn Left
   - Right Tilt → Turn Right

![image](https://github.com/user-attachments/assets/6bc8c4d2-bda3-409c-88c4-f1b742da0067)


## Scope and Future Enhancements

- Extend gesture commands (e.g., diagonal movement, rotation)
- Add camera for obstacle detection
- Integrate gesture-triggered pellet shooting for defense applications
- Use machine learning for improved gesture classification

## Conclusion

The Gesture-Controlled Robot Car provides an innovative and accessible way to interact with robotic systems using natural hand movements. With low-cost components and Arduino-based logic, this project offers a robust foundation for further enhancements in the field of human-computer interaction and robotics.

