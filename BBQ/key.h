//按键
#ifndef _KEY_H
#define _KEY_H

#include<Arduino.h>

#define KEY1 15
#define KEY2 13
#define KEY3 4
#define KEY4 5
#define KEY5 33
#define KEY6 19
#define KEY7 12
#define KEY8 32

void KEY_init();
uint8_t KEY_Scan(uint8_t mode);
// void time1_Add();
// void time1_Sub();
// void time2_Add();
// void time2_Sub();
// void time3_Add();
// void time3_Sub();
// void time4_Add();
// void time4_Sub();
#endif