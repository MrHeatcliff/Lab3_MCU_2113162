#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include"main.h"


void display7SEG(int num);
void displayTrafficLight (int id, int red, int green, int yellow);
void scan7Seg(void);
void update7SegBuffer(int time1, int time2);
void off7SEG(void);
void on7SEG(void);
#endif /* INC_OUTPUT_DISPLAY_H_ */
