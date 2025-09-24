# ParkSafe Distance Monitor

An embedded system project developed on the NXP LPC1768 ARM Cortex-M3 microcontroller to measure distance using an ultrasonic sensor (HC-SR04) and display it on a 16x2 LCD. The system enhances parking safety by providing real-time distance monitoring with LED and buzzer alerts.

---

## 📖 Abstract

The **ParkSafe Distance Monitor** is a parking safety solution designed to improve vehicle safety in congested areas. Using the HC-SR04 ultrasonic sensor, it measures the distance between vehicles and displays the result on an LCD. Smart alerts through LEDs and a buzzer are triggered when vehicles are too close, ensuring safer parking practices. This system is aligned with **Sustainable Development Goal 11 (Sustainable Cities and Communities)**, promoting safer and more efficient urban spaces.

---

## 🚗 Introduction

The project aims to develop a **real-time parking distance monitoring system** using the LPC1768 microcontroller and ultrasonic sensing. The measured distance is displayed on a **16x2 alphanumeric LCD**, and alerts are generated through:

- **LEDs** (Safe, Warning, Danger zones)  
- **Buzzer** (activated at unsafe proximity < 10 cm)  

This ensures that drivers receive **instant feedback** during parking, reducing risks of collisions and vehicle damage.  

---

## ⚙️ System Requirements

### Hardware
- **NXP LPC1768 ARM Cortex-M3 Board** – Main controller  
- **HC-SR04 Ultrasonic Sensor** – Distance measurement (2–400 cm, ±0.5 cm accuracy)  
- **16x2 Alphanumeric LCD** – Displays distance readings  
- **LEDs (Red/Yellow/Green)** – Visual zone indicators  
- **Buzzer** – Audible proximity alert  
- **Power Supply (5V)**  
- Breadboard, jumper wires, USB interface for programming  

### Software
- **Keil µVision IDE** – Development and debugging  
- **Embedded C** – Programming language  
- **Flash Magic** – To flash firmware onto LPC1768  

---

## 🔄 Working Principle

1. **Trigger Pulse**: LPC1768 sends a 10 µs pulse to the HC-SR04 TRIG pin.  
2. **Echo Reception**: The sensor transmits ultrasonic bursts and waits for the echo.  
3. **Time Measurement**: The duration of the ECHO signal (high pulse width) is measured using Timer0.  
4. **Distance Calculation**:  
   \[
   \text{Distance (cm)} = \frac{\text{Time (µs)} \times 0.0343}{2}
   \]  
5. **Output Response**:  
   - Safe Zone (>20 cm) → No alert  
   - Warning Zone (15–20 cm) → LED ON  
   - Danger Zone (<10 cm) → LED + Buzzer ON  

---

## 📂 File Structure

- `code.c` – Main logic (sensor interfacing, distance measurement, alerts)  
- `AN_LCD.c` – LCD driver functions (initialization, commands, data writing)  
- `README.md` – Documentation (this file)  

---

## 🖥️ How to Run

1. Connect LPC1768 with HC-SR04, LCD, LEDs, and Buzzer as per the circuit diagram.  
2. Open project in **Keil µVision**.  
3. Compile and flash the program to LPC1768 using **Flash Magic**.  
4. Power the board (5V supply).  
5. Observe live distance readings on LCD and alerts via LED/buzzer.  

---

## 📊 Results

- **>20 cm** → Safe zone (No alerts)  
- **15–20 cm** → LED alert (Warning)  
- **10–15 cm** → LED alert (Closer warning)  
- **<10 cm** → LED + Buzzer alert (Danger)  

This ensures reliable distance monitoring and proactive collision prevention.  

---

## ✅ Conclusion

The **ParkSafe Distance Monitor** integrates **ultrasonic sensing, real-time LCD display, and smart alert mechanisms** to create a practical parking safety system. It minimizes vehicle damage, ensures safe parking practices, and contributes to **sustainable smart city solutions**.  

---

## 🔮 Future Scope

- Integration with **smart city infrastructure**  
- Mobile app for **remote monitoring**  
- Use of **LiDAR/IR sensors** for higher accuracy  
- **Machine Learning algorithms** for predictive parking assistance  
- Adaptation for **warehouses, construction sites, and public spaces**  

---

## 👨‍💻 Author(s)

- Rebanta Mandal  

---

## 📜 License

This project is licensed under the **MIT License**.  
