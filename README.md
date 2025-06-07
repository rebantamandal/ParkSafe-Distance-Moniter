# Ultrasonic-Sensor-Embedded-Systems-

This project demonstrates how to use an LPC1768 microcontroller with an HC-SR04 ultrasonic sensor for accurate, non-contact distance measurement. The system can detect objects from 2 cm to 400 cm away by timing ultrasonic echoes.

## Features

- Accurate distance measurement (2 cm to 400 cm)
- Non-contact sensing
- Easy integration with microcontrollers

## How It Works

1. The LPC1768 sends a trigger pulse to the HC-SR04 sensor.
2. The sensor emits an ultrasonic sound wave.
3. When the wave reflects off an object, the sensor receives the echo.
4. The LPC1768 measures the time between sending and receiving the signal.
5. Distance is calculated using the formula:  
   `Distance (cm) = Time (μs) / 58`

## Applications

- Robotics navigation
- Obstacle detection
- Liquid level sensing
- Automation systems

## Hardware Required

- LPC1768 microcontroller
- HC-SR04 ultrasonic sensor
- Jumper wires
- Breadboard or PCB

## Wiring

| HC-SR04 Pin | LPC1768 Pin | Description      |
|-------------|-------------|------------------|
| VCC         | 5V          | Power supply     |
| GND         | GND         | Ground           |
| Trig        | GPIO (e.g., P2.0) | Trigger pulse    |
| Echo        | GPIO (e.g., P2.1) | Echo response    |

## Usage

1. Connect the hardware as described above.
2. Upload the firmware to the LPC1768.
3. Power on the system.
4. The measured distance will be available for further processing or display.

## License

This project is open-source and free to use for educational and non-commercial purposes.
