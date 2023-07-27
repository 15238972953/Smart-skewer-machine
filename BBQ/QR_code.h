//二维码扫描模块
#ifndef _QR_code_H
#define _QR_code_H

#include <Arduino.h>

extern String inputString;
extern bool stringComplete;

void QR_init();
int BBQ_time(String inputString);

#endif