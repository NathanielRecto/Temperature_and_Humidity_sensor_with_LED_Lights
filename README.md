# Temperature and Humidity Sensor with LED Indicators

An Arduino-based temperature and humidity monitoring system using a DHT11 sensor. The system displays real-time readings on a 16x2 LCD screen and uses three LEDs to show whether the temperature is above, below, or equal to 22°C.

This project demonstrates basic sensor input, LCD output, digital output control, and simple hardware debugging using an Arduino UNO R3.

![Project Demo](https://github.com/user-attachments/assets/c3cc33a3-904c-4b5f-a592-1393015672c1)

---

## Features

- Reads temperature and humidity using a DHT11 sensor
- Displays live readings on a 16x2 LCD display
- Uses LED indicators based on temperature:
  - Red LED turns on when the temperature is above 22°C
  - Blue LED turns on when the temperature is below 22°C
  - White LED turns on when the temperature is exactly 22°C
- Displays `ERROR` on the LCD if the DHT11 sensor fails to return a valid reading
- Uses a potentiometer to adjust the LCD contrast

---

## Components Used

| Component | Quantity | Description |
|---|---:|---|
| Arduino UNO R3 Controller Board | 1 | Main microcontroller board |
| DHT11 Temperature and Humidity Sensor | 1 | Measures temperature and humidity |
| LCD1602 16x2 Display Module | 1 | Displays sensor readings |
| 10kΩ Potentiometer | 1 | Adjusts LCD contrast |
| Red LED | 1 | Indicates temperature above 22°C |
| Blue LED | 1 | Indicates temperature below 22°C |
| White LED | 1 | Indicates temperature equal to 22°C |
| 330Ω Resistor | 3 | Limits current through each LED |
| Breadboard | 1 | Used for circuit connections |
| Jumper Wires | Several | Used to connect components |

---

## Circuit Diagram

![Circuit Diagram](https://github.com/user-attachments/assets/dadbc37a-4c1e-4c9f-a15a-e6fb094fd8d7)

---

## Schematic

![Schematic](https://github.com/user-attachments/assets/bcf68303-6a7d-4a25-841c-ac86b2743aac)

---

## Pin Connections

| Component | Arduino Pin | Purpose |
|---|---:|---|
| DHT11 Data Pin | D8 | Reads temperature and humidity data |
| Red LED | D9 | Turns on when temperature is above 22°C |
| White LED | D10 | Turns on when temperature is exactly 22°C |
| Blue LED | D11 | Turns on when temperature is below 22°C |
| LCD RS | D1 | LCD register select pin |
| LCD Enable | D2 | LCD enable pin |
| LCD D4 | D4 | LCD data pin |
| LCD D5 | D5 | LCD data pin |
| LCD D6 | D6 | LCD data pin |
| LCD D7 | D7 | LCD data pin |
| LCD VO | Potentiometer middle pin | Controls LCD contrast |
| LCD VSS | GND | Ground connection |
| LCD VDD | 5V | LCD power |
| LCD RW | GND | Sets LCD to write mode |

> Note: This project uses Arduino pin D1 for the LCD RS pin. Since D0 and D1 are also used for serial communication, moving the LCD RS pin to another digital pin is recommended if serial debugging is added later.

---

## Potentiometer Purpose

The potentiometer controls the contrast of the 16x2 LCD display. It does not affect the temperature reading, humidity reading, or LED logic.

One side of the potentiometer is connected to 5V, the other side is connected to GND, and the middle pin is connected to the LCD VO pin. Turning the knob changes the voltage going into the LCD contrast pin, which makes the text darker or lighter.

If the LCD appears blank or only shows black boxes, adjust the potentiometer until the text becomes readable.

---

## Temperature Logic

| Temperature Reading | LED Output |
|---|---|
| Above 22°C | Red LED ON |
| Below 22°C | Blue LED ON |
| Exactly 22°C | White LED ON |
| Sensor read error | LCD displays `ERROR` |

---

## How It Works

1. The Arduino reads temperature and humidity data from the DHT11 sensor.
2. The temperature and humidity values are displayed on the 16x2 LCD screen.
3. The program checks the temperature value.
4. Based on the temperature, one LED turns on:
   - Red LED for hot temperature
   - Blue LED for cold temperature
   - White LED for exactly 22°C
5. The system updates the readings every 0.5 seconds.
6. If the sensor reading fails, the LCD displays an error message.

---

## Software Setup

### 1. Install the Arduino IDE

Download and install the Arduino IDE from the official Arduino website:

[Arduino IDE Download](https://www.arduino.cc/en/software)

### 2. Clone This Repository

```bash
git clone https://github.com/NathanielRecto/Temperature_and_Humidity_sensor_with_LED_Lights.git
```

### 3. Open the Arduino Sketch

Open the project file in the Arduino IDE:

```text
Temperature_and_Humidity_sensor_with_LED_Lights.ino
```

### 4. Install Required Libraries

Install the following libraries in the Arduino IDE:

- DHT sensor library by Adafruit
- Adafruit Unified Sensor library
- LiquidCrystal library

The LiquidCrystal library is usually included with the Arduino IDE.

### 5. Upload the Code

1. Connect the Arduino UNO R3 to your computer using a USB cable.
2. Select the correct board:
   - `Tools > Board > Arduino Uno`
3. Select the correct port:
   - `Tools > Port`
4. Click the upload button.

---

## Project Structure

```text
Temperature_and_Humidity_sensor_with_LED_Lights/
├── Temperature_and_Humidity_sensor_with_LED_Lights.ino
├── README.md
└── Schematic.fzz
```
---

## Main Code Overview

The LCD is initialized using the following Arduino pins:

```cpp
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
```

The DHT11 sensor is connected to pin 8:

```cpp
#define DHTPIN 8
#define DHTTYPE DHT11
```

The LEDs are assigned to pins 9, 10, and 11:

```cpp
const int redLED = 9;
const int whiteLED = 10;
const int blueLED = 11;
```

The program checks the temperature and controls the LEDs using this logic:

```cpp
if (T > 22) {
  setLEDState(HIGH, LOW, LOW);
} else if (T < 22) {
  setLEDState(LOW, HIGH, LOW);
} else {
  setLEDState(LOW, LOW, HIGH);
}
```

---

## Troubleshooting

| Problem | Possible Fix |
|---|---|
| LCD is blank | Adjust the potentiometer until the text appears |
| LCD shows black boxes | The contrast is too high; turn the potentiometer |
| LCD shows random characters | Check the LCD RS, E, D4, D5, D6, and D7 connections |
| LCD does not update | Check the LCD power, ground, and wiring |
| LCD displays `ERROR` | Check the DHT11 VCC, GND, and data pin connections |
| Wrong LED turns on | Check the LED pin wiring and code pin assignments |
| Code does not upload | Check the selected board and port in the Arduino IDE |
| Upload fails while LCD is connected | Try disconnecting the LCD RS wire from D1 during upload, or move RS to another digital pin |

---

## Future Improvements

- Add a buzzer for audible temperature alerts
- Replace the exact 22°C condition with a temperature range
- Add a heat index calculation using both temperature and humidity
- Display decimal temperature and humidity values instead of integers
- Add serial monitor output for debugging
- Move the LCD RS pin away from D1 to avoid serial communication issues
- Add a larger display or an OLED screen
- Add data logging to store temperature and humidity readings over time

---

## Possible Code Improvement

The current white LED condition only happens when the temperature is exactly 22°C. Since sensor readings can change often, this condition may not happen for long.

A better version could use a comfort range:

```cpp
if (T > 24) {
  // Red LED ON
} else if (T < 20) {
  // Blue LED ON
} else {
  // White LED ON
}
```

This would make the white LED represent a normal or comfortable temperature range.

---

## Author

Created by Nathaniel Recto.
