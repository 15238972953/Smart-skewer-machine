//序列
#ifndef _SEQUENCE_H
#define _SEQUENCE_H


extern volatile bool ifFree[4];
extern volatile bool ifUsed[4];
extern int length;
extern int leisure;  //存放空闲烤位号

int get_first_leisure();

#endif