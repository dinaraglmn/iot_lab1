#include "Arduino.h"

#define BLUE_LED_PIN 14

void setup() {
  Serial.begin(115200);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'B') {
      digitalWrite(BLUE_LED_PIN, HIGH);
      Serial.println("BLUE=1");
    } else if (command == 'b') {
      digitalWrite(BLUE_LED_PIN, LOW);
      Serial.println("BLUE=0");
    }
  }
}