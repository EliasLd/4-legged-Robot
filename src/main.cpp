#include <Arduino.h>
#include <Servo.h>

Servo servoR;
Servo servoL;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
}

void loop() {
}