# LPC1768 with Ultrasonic Sensor

This embedded system project demonstrates how to interface an ultrasonic sensor with the LPC1768 microcontroller. The measured distance is displayed on an alphanumeric LCD using C language and standard peripheral libraries.

## Project Summary

The objective of this project is to measure distance using an ultrasonic sensor (like HC-SR04) and display the result on an LCD. It is built for the NXP LPC1768 ARM Cortex-M3 microcontroller and is ideal for learning real-time embedded applications involving timers, I/O ports, and sensor integration.

## Features

- Interfacing of HC-SR04 ultrasonic sensor with LPC1768
- Display measured distance on a 16x2 LCD
- Timer-based pulse width measurement
- Modular code structure

## Technologies Used

- C Programming
- NXP LPC1768 Microcontroller
- ARM Cortex-M3 Architecture
- Ultrasonic Sensor (HC-SR04)
- Alphanumeric LCD (16x2)

## File Structure

- `code.c` – Main logic for sensor interfacing and measurement
- `AN_LCD.c` – LCD initialization and control functions
- `README.md` – Project documentation

## How to Run

1. Open the project in Keil µVision or any compatible ARM development environment.
2. Connect the LPC1768 to the ultrasonic sensor and LCD as per your hardware schematic.
3. Compile and flash the program to the LPC1768.
4. View distance readings on the LCD.

## Hardware Requirements

- NXP LPC1768 microcontroller
- Ultrasonic Sensor (HC-SR04)
- 16x2 Alphanumeric LCD
- Jumper wires and breadboard
- Power supply (5V)

## Author(s)

- Your Name Here (you can update this section)

## License

This project is open-source and licensed under the MIT License.
