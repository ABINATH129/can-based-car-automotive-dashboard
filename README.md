# 🚗 CAN-Based Car Automotive Dashboard

A CAN-based automotive dashboard project developed using Embedded C and multiple ECUs to monitor and display vehicle parameters such as speed, RPM, gear position, and real-time information.

This project was developed as part of my Embedded Systems learning journey and focuses on CAN communication, ADC, I2C, RTC, CLCD, and microcontroller-based ECU communication.

---

## 🚀 Project Overview

The project simulates an automotive dashboard using multiple Electronic Control Units (ECUs) communicating through the CAN protocol.

Each ECU performs a specific function and exchanges required information through the CAN network.

The system demonstrates how different ECUs can communicate with each other in an automotive environment.

---

## 🏗️ System Architecture

The project consists of three ECUs:

### ECU 1 – Vehicle Data Acquisition

Responsible for collecting vehicle parameters such as:

- Speed
- RPM
- Gear position
- Analog sensor values

The collected information is transmitted through the CAN bus.

### ECU 2 – Dashboard Display

Receives vehicle information through CAN communication and displays the required parameters on the dashboard using a Character LCD.

### ECU 3 – Additional Control / Monitoring

Handles the remaining vehicle monitoring or control functionality implemented in the project.

---

## 🔄 Communication

The ECUs communicate with each other using:

**CAN (Controller Area Network)**

CAN provides communication between the different ECUs without requiring a direct connection between every individual module.

---

## ✨ Key Features

- Multi-ECU automotive system
- CAN-based communication
- Vehicle parameter monitoring
- Speed and RPM monitoring
- Gear position monitoring
- Dashboard display
- ADC-based data acquisition
- I2C communication
- RTC-based time management
- Modular Embedded C programming

---

## 🛠️ Technologies Used

- Embedded C
- PIC18F4580
- CAN Protocol
- ADC
- I2C
- RTC
- CLCD
- Microcontroller peripherals
- MPLAB X
- XC8 Compiler

---

## 📂 Project Structure

```text
CAN-Based-Car-Automotive-Dashboard/
│
├── ECU1/
├── ECU2/
├── ECU3/
├── Images/
└── README.md
