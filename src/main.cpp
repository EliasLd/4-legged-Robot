#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

#include "Moving/servoControl.h"

#define TRIGG_FRONT 12
#define ECHO_FRONT 13

Ultrasonic frontUltrasonicSensor(TRIGG_FRONT, ECHO_FRONT);

Servo servoR;
Servo servoL;

unsigned int dist = 100;
int speed = 200;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
  
}

void loop() {
    dist = frontUltrasonicSensor.read();
    Serial.print("Dist = ");
    Serial.println(dist);
    delay(5);
    if(dist > 35){
      Forward(speed, servoR, servoL);
    }
    else{
      
      Right(speed, servoR, servoL);
    }
    delay(750);
    /*
    if(dist < 20){
      while(dist < 20){
        stop(servoR, servoL);
        delay(100);
        dist = frontUltrasonicSensor.read() ;
      }
      
    }
    */
}