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
bool stop = false;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
  
}

void loop() {
    dist = frontUltrasonicSensor.read();
    delay(5);
    if(dist > 35){
      if(stop){SmoothStop(speed, servoR, servoL, &stop);}
      stop = false;
      Forward(speed, servoR, servoL);
    }
    else{
      if(!stop){SmoothStop(speed, servoR, servoL, &stop);}
      Right(speed, servoR, servoL);
    }
    delay(1000);
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