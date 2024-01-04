#include <Wire.h>

// Gas sensor analog pin
const int gasSensorPin = A0;

// LED pins
const int redLedPin = D1;
const int greenLedPin = D2;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set LED pins as output
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(gasSensorPin, INPUT);

  // Turn off LEDs initially
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasSensorPin);
  // Print gas value to serial monitor
  Serial.print("Gas Value: ");
  Serial.print(gasValue);
  int pinState = digitalRead(greenLedPin);
  Serial.println(pinState);

  // Check gas value and take appropriate action
  if (gasValue > 200) {
    // Gas detected
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    // Gas not detected
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }


  // Wait for 1 second before reading again
  delay(1000);
}