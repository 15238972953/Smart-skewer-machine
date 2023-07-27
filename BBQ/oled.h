//OLED屏幕
#ifndef _OLED_H
#define _OLED_H

#include<Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
//---------------------------------------------------------- 

void TCA9548A(uint8_t bus);
void OLED_init();
void OLED_Clear(uint8_t bus);
void OLED_ShowNum(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,int num);
void OLED_ShowChar(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,char chr);
void OLED_ShowString(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,char *p);

#endif