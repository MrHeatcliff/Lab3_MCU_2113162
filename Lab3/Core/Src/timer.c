#include "timer.h"
#include "main.h"
#include "button.h"
#define NUMBER_OF_TIMER		5

/*struct to contain timer and timer flags*/
struct {
	unsigned int timer_counter ;
	unsigned int timer_flag;
} timer[NUMBER_OF_TIMER];

void setTimer(unsigned int timer_id, unsigned int time){
	timer[timer_id].timer_counter = time *(TIMER_FREQUENCY/1000.0);
	timer[timer_id].timer_flag = 0;
}

void runTimer(void){
	for(unsigned int i = 0; i<NUMBER_OF_TIMER; i++){
		if(timer[i].timer_counter > 0){
			timer[i].timer_counter--;
			if(timer[i].timer_counter <= 0){
				timer[i].timer_flag = 1;
			}
		}
	}
}

int getTimerFlag(unsigned int timer_id){
	if(timer[timer_id].timer_flag == 1) return 1;
	else return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	runTimer();
}
