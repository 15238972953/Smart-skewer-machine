//时间管理
#ifndef _TIME_MANAGEMENT_H
#define _TIME_MANAGEMENT_H

#include<Arduino.h>

void Timer0_Open();
void Timer1_Open();
void Timer2_Open();
void Timer3_Open();
void IRAM_ATTR onTimer0();
void IRAM_ATTR onTimer1();
void IRAM_ATTR onTimer2();
void IRAM_ATTR onTimer3();

#endif