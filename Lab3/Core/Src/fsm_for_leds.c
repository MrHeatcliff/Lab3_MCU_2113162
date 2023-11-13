#include "fsm_for_leds.h"
// define an enum of 4 state of traffic light
enum {
	R_G, R_Y, G_R, Y_R
} traffic_ligt_state;

enum {
	R, Y, G, NONE
} set_state;

/*this is state of hold system
 * normal run is the system run normaly, decrease time each second
 * red_set is state to change the value of red timer
 * yellow_set is state to change the value of yellow timer
 * green_set is state to change the value of grene timer
 * not_equal is state which red_timer != green timer + yellow timer*/
enum {
	normal_run,
	red_set,
	yellow_set,
	green_set,
	not_equal
} state = normal_run;

// declare timer of leds and first traffic light state
traffic_light_state = R_G;
int timer_led1 = 13;
int timer_led2 = 10;
int red_time = 13;
int green_time = 10;
int yellow_time = 3;
// these variable is for store value when not save
int red_time_update, yellow_time_update, green_time_update;
red_time_update = 13;
yellow_time_update = 3;
green_time_update = 10;
// init traffic light state to run
void initToNormalRun(void){
	traffic_ligt_state = R_G;
	timer_led1 = red_time+1;
	timer_led2 = green_time+1;
	displayTrafficLight(0, 1, 0, 0);
	displayTrafficLight(1, 0, 1, 0);
}
// fsm for traffic light
void fsmForLeds(void){
	if(getTimerFlag(1)){
			  timer_led1--;
			  timer_led2--;
			  switch(traffic_light_state){
			  case R_G:
				  if(timer_led2 <= 0){
					  timer_led2 = yellow_time;
					  displayTrafficLight(0, 1, 0, 0);
					  displayTrafficLight(1, 0, 0, 1);
					  traffic_light_state = R_Y;
				  }
				  break;
			  case R_Y:
				  if(timer_led2 <= 0){
					  timer_led1 = green_time;
					  timer_led2 = red_time;
					  displayTrafficLight(0, 0, 1, 0);
					  displayTrafficLight(1, 1, 0, 0);
					  traffic_light_state = G_R;
				  }
				  break;
			  case G_R:
				  if(timer_led1 <= 0){
					  timer_led1 = yellow_time;
					  displayTrafficLight(0, 0, 0, 1);
					  displayTrafficLight(1, 1, 0, 0);
					  traffic_light_state = Y_R;
				  }
				  break;
			  case Y_R:
				  if(timer_led1 <= 0){
					  timer_led1 = red_time;
					  timer_led2 = green_time;
					  displayTrafficLight(0, 1, 0, 0);
					  displayTrafficLight(1, 0, 1, 0);
					  traffic_light_state = R_G;
				  }
			  default:
				  break;
			  }
			  update7SegBuffer(timer_led1, timer_led2);
			  setTimer(1, ONE_SEC);
		  }
}
// fsm to display traffic light with set state
void fsm_for_set(void){
	switch(set_state){
	// if it not set state, then turn off all traffic light
	case NONE:
		displayTrafficLight(0, 0, 0, 0);
		displayTrafficLight(1, 0, 0, 0);
		break;
	// if it is ret setting, than turn on led reds, and the same with yellow and green
	case R:
		displayTrafficLight(0, 1, 0, 0);
		displayTrafficLight(1, 1, 0, 0);
		update7SegBuffer(red_time_update, 2);
		break;
	case Y:
		displayTrafficLight(0, 0, 0, 1);
		displayTrafficLight(1, 0, 0, 1);
		update7SegBuffer(yellow_time_update, 3);
		break;
	case G:
		displayTrafficLight(0, 0, 1, 0);
		displayTrafficLight(1, 0, 1, 0);
		update7SegBuffer(green_time_update, 4);
		break;
	default:
		displayTrafficLight(0, 0, 0, 0);
		displayTrafficLight(1, 0, 0, 0);
		break;
	}
}
// funtion use to blink leds each 500ms, equal to 2Hz
void blinkyLeds(void){
	if(getTimerFlag(3)){
		switch (set_state) {
			case R:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
				// update time and present state to display on 7 segments led
				update7SegBuffer(red_time_update, 2);
				break;
			case Y:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				update7SegBuffer(yellow_time_update, 3);
				break;
			case G:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
				update7SegBuffer(green_time_update, 4);
				break;
			default:
				break;
		}
		setTimer(3, TOGGLE_TRAFFIC_LIGHT);
	}
}
// funtion use to update set state
// set state use to display traffic light and blinky traffic light
void updateSetState(int i){
	if(i == 0) set_state = NONE;
	if(i == 2) set_state = R;
	else if(i == 3) set_state = Y;
	else if(i == 4) set_state = G;
}

//fsm of hold system
void fsm(void){
	//first scan 7 segment leds to display
	if(getTimerFlag(0)){
		scan7Seg();
		setTimer(0, SCAN_7SEG);
	}
	switch(state){
	case normal_run:
		on7SEG();
		fsmForLeds();
		if(buttonPressed(0)){
			state = red_set;
			updateSetState(RED_SET);
			fsm_for_set();
		}
		break;
	case red_set:
		blinkyLeds();
		//if hold button 1, increase value of timer each 250ms
		if(buttonHold(1)){
			red_time_update++;
			if(red_time_update >=100) red_time_update = 1;
		} else if(buttonPressed(1)){
			red_time_update++;
			if(red_time_update >=100) red_time_update = 1;
		}
		// if button 0 pressed then change state
		if(buttonPressed(0)){
			state = yellow_set;
			red_time_update = red_time;
			updateSetState(YELLOW_SET);
			fsm_for_set();
		}
		// if butotn 2 pressed then save the value
		if(buttonPressed(2)){
			red_time = red_time_update;
		}
		break;
	case yellow_set:
		blinkyLeds();
		if(buttonHold(1)){
			yellow_time_update++;
			if(yellow_time_update >=100) yellow_time_update = 1;
		} else if(buttonPressed(1)){
			yellow_time_update++;
			if(yellow_time_update >=100) yellow_time_update = 1;
		}
		if(buttonPressed(0)){
			state = green_set;
			yellow_time_update = yellow_time;
			updateSetState(GREEN_SET);
			fsm_for_set();
		}
		if(buttonPressed(2)){
			yellow_time = yellow_time_update;
		}
		break;
	case green_set:
		blinkyLeds();
		if(buttonHold(1)){
			green_time_update++;
			if(green_time_update >=100) green_time_update = 1;
		} else if(buttonPressed(1)){
			green_time_update++;
			if(green_time_update >=100) green_time_update = 1;
		}
		if(buttonPressed(0)){
			// if green timer + yellow_timer = red_timer
			// change the mode to normal run
			if(red_time == green_time + yellow_time){
				state = normal_run;
				green_time_update = green_time;
				initToNormalRun();
			} else{
				//change the mode to not_equal, which will be turn off all leds
				state = not_equal;
				green_time_update = green_time;
				updateSetState(0);
				fsm_for_set();
			}

		}
		if(buttonPressed(2)){
			green_time = green_time_update;
		}
		break;
	case not_equal:
		// OFF all 7 segments leds
		off7SEG();
		if(buttonPressed(0)){
			// use button 0 to change to red set and re-set the value to equal
			state = red_set;
			updateSetState(RED_SET);
			on7SEG();
			fsm_for_set();
		}
		break;
	}
}
