#include <Arduino.h>
#include <screen.hpp>

#define PIN_BUTTON 3

Screen screen = Screen();

void button_press() {
  screen.bird_jump();
}

void setup() {
  randomSeed(analogRead(A3));
  Serial.begin(9600);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), button_press, RISING);
}

void loop() {
  screen.draw();
}
