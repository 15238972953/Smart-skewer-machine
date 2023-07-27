#include "oled.h"
Adafruit_SSD1306 display1(128, 64, &Wire, 4);
Adafruit_SSD1306 display2(128, 64, &Wire, 4);
Adafruit_SSD1306 display3(128, 64, &Wire, 4);
Adafruit_SSD1306 display4(128, 64, &Wire, 4);

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void OLED_init()
{
  TCA9548A(0);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display1.clearDisplay();

  TCA9548A(1);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.clearDisplay();
  
  TCA9548A(2);
  display3.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display3.clearDisplay();

  TCA9548A(3);
  display4.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display4.clearDisplay();
}

//清屏
void OLED_Clear(uint8_t bus){
  switch(bus){
    case 0:
      display1.clearDisplay();break;
    case 1:
      display2.clearDisplay();break;
    case 2:
      display3.clearDisplay();break;
    case 3:
      display4.clearDisplay();break;
    default:
      break;
  }
}

// 显示数字
void OLED_ShowNum(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,int num)
{
  switch(bus){
    case 0:
      TCA9548A(0);
      display1.setTextColor(WHITE); 
      display1.setTextSize(size); 
      display1.setCursor(x,y); 
      display1.print(num);
      display1.display();
      break;
    case 1:
      TCA9548A(1);
      display2.setTextColor(WHITE); 
      display2.setTextSize(size); 
      display2.setCursor(x,y); 
      display2.print(num);
      display2.display();
      break;
    case 2:
      TCA9548A(2);
      display3.setTextColor(WHITE); 
      display3.setTextSize(size); 
      display3.setCursor(x,y); 
      display3.print(num);
      display3.display();
      break;
    case 3:
      TCA9548A(3);
      display4.setTextColor(WHITE); 
      display4.setTextSize(size); 
      display4.setCursor(x,y); 
      display4.print(num);
      display4.display();
      break;
    default:
      break;
  }
  // delay(1000);
}

//显示字符
void OLED_ShowChar(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,char chr)
{
  switch(bus){
  case 0:
    TCA9548A(0);
    display1.setTextColor(WHITE); 
    display1.setTextSize(size); 
    display1.setCursor(x,y); 
    display1.print(chr);
    display1.display();
    break;
  case 1:
    TCA9548A(1);
    display2.setTextColor(WHITE); 
    display2.setTextSize(size); 
    display2.setCursor(x,y); 
    display2.print(chr);
    display2.display();
    break;
  case 2:
    TCA9548A(2);
    display3.setTextColor(WHITE); 
    display3.setTextSize(size); 
    display3.setCursor(x,y); 
    display3.print(chr);
    display3.display();
    break;
  case 3:
    TCA9548A(3);
    display4.setTextColor(WHITE); 
    display4.setTextSize(size); 
    display4.setCursor(x,y); 
    display4.print(chr);
    display4.display();
    break;
  default:
    break;
  }
}

//显示字符串
void OLED_ShowString(uint8_t bus,uint8_t size,uint8_t x,uint8_t y,char *p)
{
  while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
  {       
    OLED_ShowChar(bus,size,x,y,*p);	 
    x+=6;
    p++;
  }  
}

void OLED1_Add(){

}

void OLED1_Sub(){

}

void OLED2_Add(){

}

void OLED2_Sub(){

}

void OLED3_Add(){

}

void OLED3_Sub(){

}

void OLED4_Add(){

}

void OLED4_Sub(){

}