#include <LiquidCrystal.h>              
#include "DHT.h"                       

#define DHTPIN 8                       // Set the DHT Pin.
#define DHTTYPE DHT11                  // Set the DHT type.

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);   // Creates a LiquidCrystal object. Parameters: (RS, Enable (E), d4, d5, d6, d7).
DHT dht(DHTPIN, DHTTYPE);              // Creates a DHT object. Parameters: (DHT Pin, DHT Type).

const int redLED = 9;                  // Adds a red LED to pin 9.
const int whiteLED = 10;                // Adds a white LED to pin 10.
const int blueLED = 11;               // Adds a blue LED to pin 11.

void setup() {
  lcd.begin(16, 2);                    // Initializes the LCD screen, and sets the size (16x2).
  lcd.setCursor(0, 0);                 // Set the cursor to column 0, line 0.
  pinMode(whiteLED, OUTPUT);            // Set the white LED pin as output.
  pinMode(redLED, OUTPUT);             // Set the red LED pin as output.
  pinMode(blueLED, OUTPUT);           // Set the blue LED pin as output.

  dht.begin();                         // Initialize the DHT11 sensor.
  digitalWrite(whiteLED,LOW);           // Turn off white LED.
  digitalWrite(redLED,LOW);            // Turn off red LED.
  digitalWrite(blueLED, LOW);         // Turn off blue LED.

  lcd.print("Temperature:");           // Print "Temperature:" on the LCD screen.
  
  lcd.setCursor(0, 1);                 // Set the cursor to column 0, line 1.
  lcd.print("Humidity   :");           // Print "Humidity:" on the LCD screen.
}

// Function to set the LED states
void setLEDState(int redState, int blueState, int whiteState) {
  digitalWrite(redLED, redState);      // Set red LED state.
  digitalWrite(whiteLED, blueState);    // Set white LED state.
  digitalWrite(blueLED, whiteState);  // Set blue LED state.
}

void loop() {
  delay(500);                         // Wait 0.5 seconds before updating the values.
  float T = dht.readTemperature();    // Read temperature in Celsius.
  float H = dht.readHumidity();       // Read humidity in percentage.

  if (isnan(H) || isnan(T)) {         // Check if either temperature or humidity is NaN.
    lcd.setCursor(0, 0);
    lcd.print("ERROR          ");     // Print "ERROR" on the screen.
    return;                           // Exit the loop to avoid further operations.
  }

  // Control LEDs based on temperature
  if (T > 22) {                       // If the temperature is greater than 22°C.
    setLEDState(HIGH, LOW, LOW);      // Turn on the red LED and turn off the others.
  } else if (T < 22) {                // If the temperature is less than 22°C.
    setLEDState(LOW, HIGH, LOW);      // Turn on the blue LED and turn off the others.
  } else {                            // If the temperature is exactly 22°C.
    setLEDState(LOW, LOW, HIGH);      // Turn on the white LED and turn off the others.
  }

  // Display Temperature
  lcd.setCursor(12, 0);               // Set the cursor to column 12, line 0.
  lcd.print((int)T);                  // Print the temperature as an integer.
  lcd.print(" C ");                   // Print the Celsius unit with space.

  // Display Humidity
  lcd.setCursor(12, 1);               // Set the cursor to column 12, line 1.
  lcd.print((int)H);                  // Print the humidity as an integer.
  lcd.print(" % ");                   // Print the percentage symbol with space.
}
