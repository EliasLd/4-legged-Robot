#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

#include "Moving/servoControl.h"

#define TRIGG_FRONT 12
#define ECHO_FONT 13

Ultrasonic frontUltrasonicSensor(TRIGG_FRONT, ECHO_FONT);

Servo servoR;
Servo servoL;

unsigned int dist = 0;
int speed = 200;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
}

void loop() {
  while(true){
    Right(speed, servoR, servoL);
    unsigned int distance = frontUltrasonicSensor.read();
    Serial.print("Dist = ");
    Serial.println(distance);
    delay(500);
  }
}