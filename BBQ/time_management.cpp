#include "time_management.h"
#include "oled.h"
#include "led.h"
extern int bbq_time;
extern int leisure;  //存放空闲烤位号
extern bool ifFree[4];


/* 创建硬件定时器 */
hw_timer_t * timer = NULL;

/* LED 状态 */
volatile byte state = LOW;

void Timer_Open(uint8_t num){  //num表示esp32的定时器：0,1,2,3
  /*  1/(80MHZ/80) = 1us  */
  timer = timerBegin(num, 80, true);
 
  /* 将onTimer函数附加到我们的计时器 */
  timerAttachInterrupt(timer, &onTimer, true);
 
  /* *设置闹钟每秒调用onTimer函数1 tick为1us   => 1秒为1000000us * / 
  / *重复闹钟（第三个参数）*/
 
  timerAlarmWrite(timer, 1000000, true);
 
  /* 启动警报*/
  timerAlarmEnable(timer);
}

void IRAM_ATTR onTimer(){
  LED_control(1,state);
  state=!state;
  bbq_time--;
}
