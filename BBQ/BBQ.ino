#include "led.h"
#include "beep.h"
#include "QR_code.h"
#include "steer.h"
#include "oled.h"
#include "key.h"
#include "sequence.h"
#include "time_management.h"
#include <Arduino.h>

int bbq_time;
volatile int bbq_time1;
volatile int bbq_time2;
volatile int bbq_time3;
volatile int bbq_time4;

//记录每个位置倒计时结束的时间
int end1_time;
int end2_time;
int end3_time;
int end4_time;

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
}

unsigned long last_time=millis();
int interval_QR=500;
int interval_LED=2000;  //倒计时结束后蜂鸣器和小灯延时时间

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

  // if(bbq_time1!=last_time1){
  //   OLED_Clear(0);
  //   last_time1=bbq_time1;
  //   OLED_ShowNum(0,2,10,10,bbq_time1);
  //   Serial.println(bbq_time1);
  // }
  // if(bbq_time2!=last_time2){
  //   OLED_Clear(1);
  //   last_time2=bbq_time2;
  //   OLED_ShowNum(1,2,10,10,bbq_time2);
  // }

    // OLED_Clear(0);
    // OLED_ShowNum(0,2,10,10,bbq_time1);
    // OLED_Clear(1);
    // OLED_ShowNum(1,2,10,10,bbq_time2);
    // OLED_Clear(2);
    // OLED_ShowNum(2,2,10,10,bbq_time3);
    // OLED_Clear(3);
    // OLED_ShowNum(3,2,10,10,bbq_time4);

    // int key=KEY_Scan(0);
    // if(1==key){
    //   bbq_time1+=10;
    // }else if(2==key){
    //   bbq_time1-=10;
    // }else if(3==key){
    //   bbq_time2+=10;
    // }else if(4==key){
    //   bbq_time2-=10;
    // }else if(5==key){
    //   bbq_time3+=10;
    // }else if(6==key){
    //   bbq_time3-=10;
    // }else if(7==key){
    //   bbq_time4+=10;
    // }else if(8==key){
    //   bbq_time4-=10;
    // }
  
  // Serial.print(bbq_time1);
  // Serial.print(",");
  // Serial.print(bbq_time2);
  // Serial.print(",");
  // Serial.print(bbq_time3);
  // Serial.print(",");
  // Serial.println(bbq_time4);
  // if(bbq_time4!=last_time4){
  //   OLED_Clear(3);
  //   last_time4=bbq_time4;
  //   OLED_ShowNum(3,2,10,10,bbq_time4);
  // }

  // OLED_ShowNum(3,2,10,10,4);

  //OLED_Clear(0);
  // Serial.println(bbq_time);
  
  //二维码
  // while (Serial2.available()) {
  //   // get the new byte:
  //   char inChar = (char)Serial2.read();
  //   Serial.print(inChar);
  //   Serial.print(',');
  //   Serial.println(inputString.length());
  //   // add it to the inputString:
  //   inputString += inChar;
  //   if (inputString.length()>=5) {
  //     stringComplete = true;
  //   }
  // }


  //主程序
  if(millis()-last_time>=interval_QR){
    Serial2.begin(9600,SERIAL_8N1);
    last_time=millis();
  }
  if(stringComplete){
    stringComplete=false;
    leisure = get_first_leisure();
    bbq_time=BBQ_time(inputString);
    inputString="";  //清空字符串
    Serial.println(bbq_time);
    OLED_ShowString(leisure,1,0,0,"Please put it here.");
    delay(1000);
    switch(leisure){
      case 0:
        bbq_time1=bbq_time;
        Timer0_Open();
        break;
      case 1:
        bbq_time2=bbq_time;
        Timer1_Open();
        break;
      case 2:
        bbq_time3=bbq_time;
        Timer2_Open();
        break;
      case 3:
        bbq_time4=bbq_time;
        Timer3_Open();
        break;
      default:
        break;
    }
  }

  if(1==ifFree[0]){
    OLED_Clear(0);
    OLED_ShowNum(0,2,10,10,bbq_time1);
  }else if(0==ifFree[0]&&1==ifUsed[0]){
    digitalWrite(beep,HIGH);
    LED_control(1,1);
    end1_time=millis();
    ifUsed[0]=0;
  }else if(0==ifFree[0] && 0==ifUsed[0] && (millis()-end2_time>=interval_LED)){
    digitalWrite(beep,LOW);
    LED_control(2,0);
  }

  if(1==ifFree[1]){
    OLED_Clear(1);
    OLED_ShowNum(1,2,10,10,bbq_time2);
  }else if(0==ifFree[1]&&1==ifUsed[1]){
    digitalWrite(beep,HIGH);
    LED_control(2,1);
    end2_time=millis();
    ifUsed[1]=0;
  }else if(0==ifFree[1]&&0==ifUsed[1]&&(millis()-end2_time>=interval_LED)){
      digitalWrite(beep,LOW);
      LED_control(2,0);
  }

  if(1==ifFree[2]){
    OLED_Clear(2);
    OLED_ShowNum(2,2,10,10,bbq_time3);
  }else if(0==ifFree[2]&&1==ifUsed[2]){
    digitalWrite(beep,HIGH);
    LED_control(3,1);
    end3_time=millis();
    ifUsed[2]=0;
  }else if(0==ifFree[2]&&0==ifUsed[2]&&(millis()-end3_time>=interval_LED)){
      digitalWrite(beep,LOW);
      LED_control(3,0);
  }

  if(1==ifFree[3]){
    OLED_Clear(3);
    OLED_ShowNum(3,2,10,10,bbq_time4);
  }else if(0==ifFree[3]&&1==ifUsed[3]){
    digitalWrite(beep,HIGH);
    LED_control(4,1);
    end4_time=millis();
    ifUsed[3]=0;
  }else if(0==ifFree[3]&&0==ifUsed[3]&&(millis()-end4_time>=interval_LED)){
    digitalWrite(beep,LOW);
    LED_control(4,0);
  }
    
  int key=KEY_Scan(0);
  if(1==key){
    bbq_time1+=10;
  }else if(2==key){
    bbq_time1-=10;
  }else if(3==key){
    bbq_time2+=10;
  }else if(4==key){
    bbq_time2-=10;
  }else if(5==key){
    bbq_time3+=10;
  }else if(6==key){
    bbq_time3-=10;
  }else if(7==key){
    bbq_time4+=10;
  }else if(8==key){
    bbq_time4-=10;
  }

  for(int i=0;i<length;i++){
    Serial.print(ifFree[i]);
  }
  Serial.println();
}
