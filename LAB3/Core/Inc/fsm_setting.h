/*
 * fsm_setting.h
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#define MODE1	0
#define MODE2 	1
#define MODE3	2
#define MODE4	3

#define RED		1
#define	YELLOW	2
#define GREEN	3

extern int valueSetting;

void blinkyLed(int LED);
void fsm_setting();

#endif /* INC_FSM_SETTING_H_ */
