#include "sequence.h"

bool ifFree[4]={0,0,0,0};  //0表示该位置没有烤串，1表示有烤串
int length=sizeof(ifFree)/sizeof(ifFree[0]);
int time1=0,time2=0,time3=0,time4=0;
int leisure;  //存放空闲烤位号

//得到目前空闲的烤位
int get_first_leisure(){
  for(int i=0;i<length;i++){
    if(0==ifFree[i]){
      ifFree[i]=1;
      return i;
    }
  }
  return -1; //表示所有的烤位都满了
}