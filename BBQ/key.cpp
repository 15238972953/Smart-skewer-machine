#include "key.h"
#include "oled.h"

volatile bool button1_Pressed = false;

void KEY_init(){
  pinMode(KEY1,INPUT_PULLUP);
  pinMode(KEY2,INPUT_PULLUP);
  pinMode(KEY3,INPUT_PULLUP);
  pinMode(KEY4,INPUT_PULLUP);
  pinMode(KEY5,INPUT_PULLUP);
  pinMode(KEY6,INPUT_PULLUP);
  pinMode(KEY7,INPUT_PULLUP);
  pinMode(KEY8,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(KEY1), OLED1_Add, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY2), OLED1_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY3), OLED2_Add, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY4), OLED2_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY5), OLED3_Add, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY6), OLED3_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY7), OLED4_Add, FALLING);  //设置触发中断的模式和中断服务函数
  attachInterrupt(digitalPinToInterrupt(KEY8), OLED4_Sub, FALLING);  //设置触发中断的模式和中断服务函数
}

uint8_t KEY_Scan(uint8_t mode)
{	 
	static uint8_t key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(digitalRead(KEY1)==0||digitalRead(KEY2)==0||digitalRead(KEY3)==0)||digitalRead(KEY4)==0||
      digitalRead(KEY5)==0||digitalRead(KEY6)==0||digitalRead(KEY7)==0||digitalRead(KEY8)==0)
	{
		delay(10);//去抖动 
		key_up=0;
		if(digitalRead(KEY1)==0)return 1;
		else if(digitalRead(KEY2)==0)return 2;
		else if(digitalRead(KEY3)==0)return 3;
    else if(digitalRead(KEY4)==0)return 4;
    else if(digitalRead(KEY5)==0)return 5;
		else if(digitalRead(KEY6)==0)return 6;
    else if(digitalRead(KEY7)==0)return 7;
    else if(digitalRead(KEY8)==0)return 8;
	}else if(digitalRead(KEY1)==1&&digitalRead(KEY2)==1&&digitalRead(KEY3)==1&&digitalRead(KEY4)==1&&
      digitalRead(KEY5)==1&&digitalRead(KEY6)==1&&digitalRead(KEY7)==1&&digitalRead(KEY8)==1)key_up=1; 	    
 	return 0;// 无按键按下
}



