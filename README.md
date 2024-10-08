# LED Temp-Humidity Indicator Project
An Arduino-based system designed to monitor temperature and humidity using a DHT11 sensor. The system displays real-time data on a 16x2 LCD screen and activates LED lights based on the current temperature. It is a simple yet engaging project, perfect for understanding sensor integration and controlling outputs in microcontoller environments.

![IMG_8610](https://github.com/user-attachments/assets/c3cc33a3-904c-4b5f-a592-1393015672c1)
## Features
- Real-Time Monitoring: Displays temperature and humidity readings on a 16x2 LCD display.
- LED indicators:
  - Red LED for temperatures above 22°C.
  - Blue LED for temperatures below 22°C.
  - White LED for exactly 22°C.
- Error Handling: Displays an error message on the LCD if the sensor fails to read the temperature or humidity.

## Components Used
- UNO R3 Controller Board
- DHT11 Temperature & Humidity Sensor (3 pins)
- LCD1602 Module (with pin header)
- 3 LEDs (Red, Blue, White)
- 3 Resistors (330 ohms)
- Breadboard
- Jumper Wires

## Circuit Diagram

![Schematic_bb](https://github.com/user-attachments/assets/dadbc37a-4c1e-4c9f-a15a-e6fb094fd8d7)

## Schematic

![project_schem](https://github.com/user-attachments/assets/bcf68303-6a7d-4a25-841c-ac86b2743aac)
## Setup And Installation
### Hardware Setup
1. Connect the DHT11 sensor:
   - Data pin to pin 8 on the UNO R3 Controller Board.
   - VCC to 5V and GND to GND.
2. Connect the LEDs:
   - Red LED to pin 9, Blue LED to pin 10, and White LED to pin 11.
   - Each LED should have a 330-ohm resistor connected in series.
3. Connect the LCD
   - Use the LiquidCrystal library's default pins for RS, E, d4, d5, d6, and d7.
4. Connect everything using jumper wires and a breadboard for proper electrical connections.
### Software Setup
1. Install Arduino IDE: Download and install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Clone this Repository:
    - "git clone https://github.com/NathanielRecto/Temperature_and_Humidity_sensor_with_LED_Lights.git"
4. Open the Sketch:
   - Open the Temperature_and_Humidity_sensor_with_LED_Lights.ino
5. Install the Required Libraries:
   - Install the DHT library by Adafruit for reading temperature and humidity sensor.
   - Install the LiquidCrystal library to control the LCD.
6. Upload the Code:
    - Connect your UNO R3 Controller Baord to your computer via USB.
    - Select the coorect board and port in the Arduino IDE.
    - Click on the upload button to load the code onto the board. 
## How it Works
1. The DHT11 sensor reads the temperature and humidity from the environment.
2. The values are displayed on the 16x2 LCD display.
3. Based on the temperatures:
   - The red LED lights up if the temperature is above 22°C.
   - The blue LED lights up if the temperature is below 22°C.
   - The white LED lights up if the temperature is exactly 22°C.
4. The system continuously updates the values every 0.5 seconds.

## Future Improvements
- Add a buzzer for audible alerts when temperature exceeds a certain threshold.
- Include more detailed environmental controls, such as linking to an air conditioning unit.
   
