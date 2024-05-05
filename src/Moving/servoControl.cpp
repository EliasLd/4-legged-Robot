#include "servoControl.h"

#include <Servo.h>
#include <Arduino.h>

void Forward(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 - speed);
  servoL.writeMicroseconds(1500 + speed);
  Serial.println("Avance");
  delay(10);
}

void Backward(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 + speed);
  servoL.writeMicroseconds(1500 - speed);
  Serial.println("Recule");
  delay(10);
}

void Right(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 + speed);
  servoL.writeMicroseconds(1500 + speed);
  Serial.println("Droite");
  delay(10);
}

void Left(int speed, Servo servoR, Servo servoL){
  servoR.writeMicroseconds(1500 - speed);
  servoL.writeMicroseconds(1500 + speed);
  Serial.println("Gauche");
  delay(10);
}

void SmoothStop(int speed, Servo servoR, Servo servoL, bool *stop){
   int s = speed;
   while(s > 0)
   {
     s -= 15;
     servoR.writeMicroseconds(1500 + s);
     servoL.writeMicroseconds(1500 + s);
     delay(10);
   }
   if(*stop == false){
    *stop = true;
   }
}
