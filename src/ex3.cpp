#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  int rawValue = analogRead(LIGHT_SENSOR_PIN);
  
  Serial.print("raw=");
  Serial.println(rawValue);

  delay(500); // Read every 500 ms
}