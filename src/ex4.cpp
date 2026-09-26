#include "Arduino.h"

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define BLUE_LED_PIN   14
#define YELLOW_LED_PIN 12
#define LIGHT_SENSOR_PIN 33

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  int value = analogRead(LIGHT_SENSOR_PIN);

  // Turn all LEDs off first
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  if (value >= 0 && value <= 1023) {
    digitalWrite(BLUE_LED_PIN, HIGH);
    Serial.println("band=BLUE");
  } else if (value >= 1024 && value <= 2047) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    Serial.println("band=GREEN");
  } else if (value >= 2048 && value <= 3071) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    Serial.println("band=YELLOW");
  } else if (value >= 3072 && value <= 4095) {
    digitalWrite(RED_LED_PIN, HIGH);
    Serial.println("band=RED");
  }

  delay(500);
}