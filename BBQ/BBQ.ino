#include "led.h"
#include "beep.h"
#include "QR_code.h"
#include "steer.h"
#include "oled.h"
#include "key.h"
#include "sequence.h"
#include "time_management.h"

int bbq_time=20;
int last_time=bbq_time;
int key;
void setup() {
  //外设初始化
  Serial.begin(9600);
  LED_init();
  BEEP_init();
  QR_init();
  STEER_init();
  OLED_init();
  KEY_init();
  STEER_move(100);
  Timer_Open(0);
  // Timer_Open(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  //测试
  //OLED_ShowString(0,1,0,0,"Please put it here.");
  // OLED_ShowNum(0,1,0,0,3);

  // LED_control(4,0);
  // LED_control(1,0);
  // LED_control(2,0);
  // if(0==digitalRead(KEY7)){
  //   LED_control(4,1);
  // }else if(0==digitalRead(KEY1)){
  //   LED_control(1,1);
  //   LED_control(2,1);
  // }
  // OLED_ShowNum(0,2,0,0,0);
  // delay(2000);
  // OLED_Clear(0);
  // OLED_ShowNum(1,2,10,0,1);
  // delay(2000);
  // OLED_Clear(1);
  // OLED_ShowNum(2,2,20,0,2);
  // delay(2000);
  // OLED_Clear(2);
  // OLED_ShowNum(3,2,30,0,3);
  // delay(2000);
  // OLED_Clear(3);
  // while(1){

  // }
  
  // static int a=1,b=1;
  // if(a){
  //   leisure = get_first_leisure();
  //   bbq_time=BBQ_time("222222");
  //   if(bbq_time<0){
  //     OLED_Clear(leisure);
  //     OLED_ShowString(leisure,2,2,0,"ERROR!");
  //   }
  //   OLED_ShowString(leisure,1,0,0,"Please put it here.");
  //   OLED_ShowNum(leisure,2,10,10,bbq_time);
  //   a=0;
  // }
  // if(b){
  // leisure = get_first_leisure();
  // bbq_time=BBQ_time("333333");
  // if(bbq_time<0){
  //   OLED_Clear(leisure);
  //   OLED_ShowString(leisure,2,2,0,"ERROR!");
  // }
  // OLED_ShowString(leisure,1,0,0,"Please put it here.");
  // OLED_ShowNum(leisure,2,10,10,bbq_time);
  // a=0;
  // }
  // static int a=60,b=90;
  // OLED_ShowNum(0,2,10,10,--a);
  // OLED_Clear(0);
  // OLED_ShowNum(1,2,10,10,--b);
  // OLED_Clear(1);
  // delay(1000);
  // if(a==0){
  //   OLED_Clear(0);
  //   LED_control(1,1);
  // }
  // if(b==0){
  //   OLED_Clear(1);
  //   LED_control(2,1);
  // }
  //OLED
  static int a=1;
  if(a==1){
    OLED_ShowChar(1,2,0,0,'a');
    OLED_Clear(1);
    a=0;
  }
  if(bbq_time!=last_time){
     OLED_Clear(0);
    last_time=bbq_time;
  }
  OLED_ShowNum(0,2,10,10,bbq_time);
  key=KEY_Scan(0);
  Serial.println(key);
  if(1==key){
    bbq_time=bbq_time+10;
  }else if(2==key){
    bbq_time=bbq_time-10;
  }
  //OLED_Clear(0);
  // Serial.println(bbq_time);
  //主程序

  // if(stringComplete){
  //   stringComplete=false;
  //   leisure = get_first_leisure();
  //   bbq_time=BBQ_time(inputString);
  //   Serial.println(bbq_time);
  //   OLED_ShowString(leisure,1,0,0,"Please put it here.");
  //   Timer_Open(leisure);
  //   //OLED_ShowNum(leisure,2,10,10,bbq_time);

  // }

}
