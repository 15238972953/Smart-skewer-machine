//舵机
#ifndef _STEER_H
#define _STEER_H

#include<Arduino.h>
// #include<Servo.h>
// Servo myservo;

#define STEER 25

void STEER_init();
void STEER_move(int speed);
#endif