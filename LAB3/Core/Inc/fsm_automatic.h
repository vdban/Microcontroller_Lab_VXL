/*
 * fsm_automatic.h
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

extern int timeRed;
extern int timeYellow;
extern int timeGreen;

extern int count;
extern int autoStatus;

#define RED_GREEN	1
#define RED_YELLOW	2
#define	GREEN_RED	3
#define	YELLOW_RED	4

void allLEDoff();
void fsm_automatic();

#endif /* INC_FSM_AUTOMATIC_H_ */
