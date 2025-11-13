/*
 * global.h
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button_reading.h"
#include "display_7seg.h"
#include "fsm_automatic.h"
#include "fsm_setting.h"
#include "main.h"
#include "software_timer.h"

extern int autoStatus;

extern int timeRed;
extern int timeYellow;
extern int timeGreen;

extern int count;

extern int FSM_STATUS;
extern int valueSetting;
extern int BLINKY_LED_STATUS;

extern int led_buffer[];
extern int STATUS_7SEG;
extern int TIME_7SEG;

#endif /* INC_GLOBAL_H_ */
