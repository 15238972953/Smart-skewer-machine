#include "time_management.h"
extern int bbq_time1;
extern int bbq_time2;
extern int bbq_time3;
extern int bbq_time4;
extern int leisure;  //存放空闲烤位号
extern volatile bool ifFree[4];
extern volatile bool ifUsed[4];

  /* 创建硬件定时器 */
hw_timer_t * timer0 = NULL;
hw_timer_t * timer1 = NULL;
hw_timer_t * timer2 = NULL;
hw_timer_t * timer3 = NULL;

//esp32的4个定时器：0,1,2,3
//定时器0
void Timer0_Open(){  
  /*  1/(80MHZ/80) = 1us  */
  timer0 = timerBegin(0, 80, true);
  /* 将onTimer函数附加到我们的计时器 */
  timerAttachInterrupt(timer0, &onTimer0, true);
  /* *设置闹钟每秒调用onTimer函数1 tick为1us   => 1秒为1000000us * / 
  / *重复闹钟（第三个参数）*/
  timerAlarmWrite(timer0, 1000000, true);
  /* 启动警报*/
  timerAlarmEnable(timer0);
}

//定时器1
void Timer1_Open(){  
  /*  1/(80MHZ/80) = 1us  */
  timer1 = timerBegin(1, 80, true);
  /* 将onTimer函数附加到我们的计时器 */
  timerAttachInterrupt(timer1, &onTimer1, true);
  /* *设置闹钟每秒调用onTimer函数1 tick为1us   => 1秒为1000000us * / 
  / *重复闹钟（第三个参数）*/
  timerAlarmWrite(timer1, 1000000, true);
  /* 启动警报*/
  timerAlarmEnable(timer1);
}

//定时器2
void Timer2_Open(){  
  /*  1/(80MHZ/80) = 1us  */
  timer2 = timerBegin(2, 80, true);
  /* 将onTimer函数附加到我们的计时器 */
  timerAttachInterrupt(timer2, &onTimer2, true);
  /* *设置闹钟每秒调用onTimer函数1 tick为1us   => 1秒为1000000us * / 
  / *重复闹钟（第三个参数）*/
  timerAlarmWrite(timer2, 1000000, true);
  /* 启动警报*/
  timerAlarmEnable(timer2);
}

//定时器3
void Timer3_Open(){ 
  /*  1/(80MHZ/80) = 1us  */
  timer3 = timerBegin(3, 80, true);
  /* 将onTimer函数附加到我们的计时器 */
  timerAttachInterrupt(timer3, &onTimer3, true);
  /* *设置闹钟每秒调用onTimer函数1 tick为1us   => 1秒为1000000us * / 
  / *重复闹钟（第三个参数）*/
  timerAlarmWrite(timer3, 1000000, true);
  /* 启动警报*/
  timerAlarmEnable(timer3);
}

void IRAM_ATTR onTimer0(){
  bbq_time1--;
  if(bbq_time1<0){
    ifFree[0]=0;
    ifUsed[0]=1;
    timerStop(timer0);
  }
}

void IRAM_ATTR onTimer1(){
  bbq_time2--;
  if(bbq_time2<0){
    ifFree[1]=0;
    ifUsed[1]=1;
    timerStop(timer1);
  }
}

void IRAM_ATTR onTimer2(){
  bbq_time3--;
  if(bbq_time3<0){
    ifFree[2]=0;
    ifUsed[2]=1;
    timerStop(timer2);
  }
}

void IRAM_ATTR onTimer3(){
  bbq_time4--;
  if(bbq_time4<0){
    ifFree[3]=0;
    ifUsed[3]=1;
    timerStop(timer3);
  }
}
