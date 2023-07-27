#include "key.h"
#include "oled.h"

volatile bool button1_Pressed = false;
extern int bbq_time1;
extern int bbq_time2;
extern int bbq_time3;
extern int bbq_time4;

void KEY_init(){
  pinMode(KEY1,INPUT_PULLUP);
  pinMode(KEY2,INPUT_PULLUP);
  pinMode(KEY3,INPUT_PULLUP);
  pinMode(KEY4,INPUT_PULLUP);
  pinMode(KEY5,INPUT_PULLUP);
  pinMode(KEY6,INPUT_PULLUP);
  pinMode(KEY7,INPUT_PULLUP);
  pinMode(KEY8,INPUT_PULLUP);

  // attachInterrupt(digitalPinToInterrupt(KEY1), time1_Add, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY2), time1_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY3), time2_Add, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY4), time2_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY5), time3_Add, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY6), time3_Sub, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY7), time4_Add, FALLING);  //设置触发中断的模式和中断服务函数
  // attachInterrupt(digitalPinToInterrupt(KEY8), time4_Sub, FALLING);  //设置触发中断的模式和中断服务函数
}

//轮询方式
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

// void time1_Add(){
//   delay(10);
//   if(0==digitalRead(KEY1))
//     bbq_time1=bbq_time1+10;
// }

// void time1_Sub(){
//   delay(10);
//   if(0==digitalRead(KEY2))
//     bbq_time1=bbq_time1-10;
// }

// void time2_Add(){
//   delay(10);
//   if(0==digitalRead(KEY3))
//     bbq_time2=bbq_time2+10;
// }

// void time2_Sub(){
//   delay(10);
//   if(0==digitalRead(KEY4))
//     bbq_time2=bbq_time2-10;
// }

// void time3_Add(){
//   delay(10);
//   if(0==digitalRead(KEY5))
//     bbq_time3=bbq_time3+10;
// }

// void time3_Sub(){
//   delay(10);
//   if(0==digitalRead(KEY6))
//     bbq_time3=bbq_time3-10;
// }

// void time4_Add(){
//   delay(10);
//   if(0==digitalRead(KEY7))
//     bbq_time4=bbq_time4+10;
// }

// void time4_Sub(){
//   delay(10);
//   if(0==digitalRead(KEY8))
//     bbq_time4=bbq_time4-10;
// }

