#include "Keyboard.h"

// set pin numbers for the five buttons:
const int inputPin = 5;
const int inputPin2 = 7;

int buttonState;             // the current reading from the input pin
int buttonState2;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int lastButtonState2 = LOW;   // the previous reading from the input pin

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 30;    // the debounce time; increase if the output flickers

void setup() { // initialize the buttons' inputs:
  pinMode(inputPin, INPUT);
  pinMode(inputPin2, INPUT);
  Keyboard.begin();
  digitalWrite(inputPin2, LOW);
  digitalWrite(inputPin, LOW);
}

void loop() {
  int reading = digitalRead(inputPin);
  int reading2 = digitalRead(inputPin2);

  if (reading != lastButtonState && reading2 != lastButtonState2) {
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
    } else if (reading2 != buttonState2) {
      buttonState2 = reading2;

      if (buttonState2 == HIGH) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('c');
        delay(30);
        Keyboard.releaseAll();
      }
    }
  }
  lastButtonState = reading;
  lastButtonState2 = reading2;
}
