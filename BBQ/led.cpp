#include "led.h"

void LED_init(){
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
}

void LED_control(int led,bool state){
  switch(led){
    case 1:
      digitalWrite(LED1,state);
      break;
    case 2:
      digitalWrite(LED2,state);
      break;
    case 3:
      digitalWrite(LED3,state);
      break;
    case 4:
      digitalWrite(LED4,state);
      break;
    default:
      break;
  }
}

