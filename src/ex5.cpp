#include "Arduino.h"

#define YELLOW_LED_PIN   12
#define BUTTON_PIN       25
#define LIGHT_SENSOR_PIN 33

bool lastButtonState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // On button press edge (released -> pressed)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    int value = analogRead(LIGHT_SENSOR_PIN);
    
    // Print snapshot reading
    Serial.print("snapshot=");
    Serial.println(value);

    // Flash Yellow LED for 100 ms as acknowledgment
    digitalWrite(YELLOW_LED_PIN, HIGH);
    delay(100);
    digitalWrite(YELLOW_LED_PIN, LOW);
  }

  lastButtonState = currentButtonState;
}