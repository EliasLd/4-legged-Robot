#include "servoControl.h"

#include <Servo.h>
#include <Arduino.h>

void Forward(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 + speed);
  servoL.writeMicroseconds(1500 + speed);
  delay(10);
}

void Backward(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 - speed);
  servoL.writeMicroseconds(1500 - speed);
  delay(10);
}

void Right(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 - speed);
  servoL.writeMicroseconds(1500 + speed);
  delay(10);
}

void Left(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 + speed);
  servoL.writeMicroseconds(1500 - speed);
  delay(10);
}

bool SmoothStop(int speed, Servo servoR, Servo servoL){
   int s = speed;
   while(s != 0)
   {
     s -= 25;
     servoR.writeMicroseconds(1500 + s);
     servoL.writeMicroseconds(1500 + s);
     delay(10);
   }
   return true;
}
