//按键
#ifndef _KEY_H
#define _KEY_H

#include<Arduino.h>

#define KEY1 15
#define KEY2 2
#define KEY3 4
#define KEY4 5
#define KEY5 33
#define KEY6 19
#define KEY7 12
#define KEY8 32

void KEY_init();
uint8_t KEY_Scan(uint8_t mode);
#endif