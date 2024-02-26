#include <Arduino.h>
#include <Servo.h>

void Forward(int speed, Servo servoR, Servo servoL);
void Backward(int speed, Servo servoR, Servo servoL);
void Right(int speed, Servo servoR, Servo servoL);
void Left(int speed, Servo servoR, Servo servoL);
void SmoothStop(int speed, Servo servoR, Servo servoL, bool *stop);

