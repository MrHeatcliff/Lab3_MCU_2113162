#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_FREQUENCY			100//100Hz
#define READ_BUTTON_TIMER		50//50ms
#define TOGGLE_TRAFFIC_LIGHT	500//500ms = 2Hz
#define ONE_SEC					1000// 1s
#define SCAN_7SEG				50//ms

void setTimer(unsigned int timer_id, unsigned int time);
void runTimer(void);
int getTimerFlag(unsigned int timer_id);
#endif /* INC_TIMER_H_ */
