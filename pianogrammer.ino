#include "Keyboard.h"

// set pin numbers for the five buttons:
const int inputPin = 5;
const int outputPin = 7;

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 30;    // the debounce time; increase if the output flickers

void setup() { // initialize the buttons' inputs:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);

  Keyboard.begin();
  digitalWrite(outputPin, LOW);
  digitalWrite(inputPin, LOW);
}

void loop() {
  int reading = digitalRead(inputPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        delay(30);
        Keyboard.releaseAll();
      }
    }
  }
  lastButtonState = reading;
}
