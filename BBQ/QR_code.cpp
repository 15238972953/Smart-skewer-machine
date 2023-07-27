#include "QR_code.h"

String inputString = "";         // a string to hold incoming data
bool stringComplete = false;  // whether the string is complete

void QR_init(){
  Serial2.begin(9600,SERIAL_8N1);
}

//串口中断函数
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

//得到烧烤时间
int BBQ_time(String inputString){
  int bbq_time = 0;
  switch(inputString[0]){
    case '1':
      bbq_time=30;    //单位：s
      break;
    case '2':
      bbq_time=60;
      break;
    case '3':
      bbq_time=90;
      break;
    case '4':
      bbq_time=120;
      break;
    default:
      bbq_time=-1;
      break;
  }
  return bbq_time;
}