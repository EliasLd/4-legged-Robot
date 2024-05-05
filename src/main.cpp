#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

#include "Moving/servoControl.h"

#define TRIGG_FRONT 12
#define ECHO_FRONT 13

#define TRIGG_BACK 8
#define ECHO_BACK 9


Ultrasonic frontUltrasonicSensor(TRIGG_FRONT, ECHO_FRONT);
Ultrasonic BackUltrasonicSensor(TRIGG_BACK, ECHO_BACK);

Servo servoR;
Servo servoL;

int sonorPin = A0;

unsigned int dist = 100;
unsigned int back_dist = 0;
unsigned int song = 0;

int speed = 200;

bool stop = false;

void setup() {
  Serial.begin(115200);
  servoR.attach(10);
  servoL.attach(11);
}

void loop() {
    //song = analogRead(sonorPin);
    dist = frontUltrasonicSensor.read();
    back_dist = BackUltrasonicSensor.read();
    Serial.println(song);
    Serial.println(dist);
    delay(5);

    if(back_dist < 30){
      if(back_dist < 15){
        speed +=  (30 - back_dist) + 70;
      }
      speed +=  (30 - back_dist) + 20;
    }
    else{
      speed = 200;
    }

    if(dist > 35 && dist != 0){
      if(stop){SmoothStop(speed, servoR, servoL, &stop);}
      stop = false;
      Forward(speed, servoR, servoL);
    }
    else{
      if(!stop){SmoothStop(speed, servoR, servoL, &stop);}
      Right(speed, servoR, servoL);
    }
    delay(1000);
}