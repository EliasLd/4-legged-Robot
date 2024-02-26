#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

#include "Moving/servoControl.h"

Servo servoR;
Servo servoL;

int speed = 200;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
}

void loop() {
  while(true){
    Right(speed, servoR, servoL);
  }
}