# Smart LED Motion Detector 📦

An Arduino-based motion detection system that automatically turns on an LED when motion is detected within a specified range (30 cm). The LED stays on for 5 seconds before turning off automatically. Ideal for smart lighting applications in dark hallways, entrances, or bathrooms.

## Overview

This project uses an ultrasonic sensor (HC-SR04) to detect the presence of objects or people within a configurable distance threshold. When motion is detected, the system turns on an LED for a set duration before automatically turning it off.

## Hardware Requirements

- Arduino board (Uno, Nano, or similar)
- HC-SR04 Ultrasonic Sensor
- LED
- 220Ω resistor (for the LED)
- Jumper wires
- Breadboard

## Circuit Diagram

Connect the components as follows:

- **HC-SR04 Ultrasonic Sensor**:
  - VCC → 5V on Arduino
  - GND → GND on Arduino
  - TRIG → Pin 6 on Arduino
  - ECHO → Pin 7 on Arduino

- **LED**:
  - Anode (longer leg) → 220Ω resistor → Pin 13 on Arduino
  - Cathode (shorter leg) → GND on Arduino

## Software

The Arduino sketch (`motion_sensor_led.cpp`) contains all the logic for:
- Measuring distance using the ultrasonic sensor
- Detecting when an object is within the threshold distance
- Turning the LED on for a specified duration
- Outputting distance readings to the Serial monitor

## Configuration

You can modify the following constants in the code to customize the behavior:

- `TRIG_PIN`: The pin connected to the TRIG pin of the ultrasonic sensor (default: 6)
- `ECHO_PIN`: The pin connected to the ECHO pin of the ultrasonic sensor (default: 7)
- `LED_PIN`: The pin connected to the LED (default: 13)
- `DISTANCE_THRESHOLD`: The maximum distance (in cm) at which motion will trigger the LED (default: 30cm)
- `LIGHT_DURATION`: How long the LED stays on after motion is detected (default: 5000ms or 5 seconds)

## Installation

1. Connect the hardware components according to the circuit diagram
2. Open the Arduino IDE
3. Create a new sketch and copy the contents of `motion_sensor_led.cpp`
4. Upload the sketch to your Arduino board
5. Open the Serial Monitor (set to 9600 baud) to view distance readings

## Usage

Once installed, the system will:
1. Continuously measure the distance to the nearest object
2. When an object comes within the specified threshold distance, the LED will turn on
3. The LED will remain on for the specified duration (default: 5 seconds)
4. After the duration expires, the LED will turn off automatically
5. The system will continue monitoring for new motion

## Troubleshooting

- If the LED doesn't turn on, check all connections and ensure the LED is oriented correctly
- If distance readings seem incorrect, ensure the ultrasonic sensor is properly connected
- For more accurate readings, avoid using the sensor in environments with soft materials that absorb sound waves

## License

This project is open source and available under the [MIT License](LICENSE).

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
