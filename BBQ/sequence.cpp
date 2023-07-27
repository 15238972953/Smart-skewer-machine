#include "sequence.h"

volatile bool ifFree[4]={0,0,0,0};  //0表示该位置没有烤串，1表示有烤串
volatile bool ifUsed[4]={0,0,0,0};   //判断当前这个位置是否已被使用过，如果已经被使用过，则置1，则当该位置ifUsed为1且ifFree为0时，表示这个位置有烤串刚被烤完；
int length=sizeof(ifFree)/sizeof(ifFree[0]);
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