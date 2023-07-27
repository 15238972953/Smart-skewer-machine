//时间管理
#ifndef _TIME_MANAGEMENT_H
#define _TIME_MANAGEMENT_H

#include<Arduino.h>

void Timer_Open(uint8_t num);
void IRAM_ATTR onTimer();

#endif