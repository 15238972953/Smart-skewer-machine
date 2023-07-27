//小灯
#ifndef _LED_H
#define _LED_H

#include<Arduino.h>

#define LED1 18
#define LED2 23
#define LED3 14
#define LED4 27

void LED_init();
void LED_control(int led,bool state);

#endif