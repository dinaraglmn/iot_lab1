#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN    25

bool greenState = false;
bool lastButtonState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT); // Button is active HIGH
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    greenState = !greenState; // Toggle LED state
    digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
    
    // Print updated status over Serial
    Serial.print("GREEN=");
    Serial.println(greenState ? 1 : 0);

    delay(50); 
  }

  lastButtonState = currentButtonState;
}