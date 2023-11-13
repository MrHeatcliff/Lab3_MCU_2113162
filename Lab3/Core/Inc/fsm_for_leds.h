#ifndef INC_FSM_FOR_LEDS_H_
#define INC_FSM_FOR_LEDS_H_

#include "output_display.h"
#include "button.h"
#include "fsm_for_leds.h"
#include "timer.h"
#include "main.h"

#define RED_SET 	2
#define YELLOW_SET	3
#define GREEN_SET	4


void fsmForLeds(void);
void blinkyLeds(void);
void updateSetState(int i);
#endif /* INC_FSM_FOR_LEDS_H_ */
