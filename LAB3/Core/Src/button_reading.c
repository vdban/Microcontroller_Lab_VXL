/*
 * button_reading.c
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#include "button_reading.h"
#include "main.h"
#include "software_timer.h"

struct ButtonType {
	int key0;
	int key1;
	int key2;
	int oldState;
	int flag;
};

// Init 3 buttons
struct ButtonType button1 = {RELEASED, RELEASED, RELEASED, RELEASED, 0};
struct ButtonType button2 = {RELEASED, RELEASED, RELEASED, RELEASED, 0};
struct ButtonType button3 = {RELEASED, RELEASED, RELEASED, RELEASED, 0};

/**
 * 	@brief:		Handles debounce logic for button1
 *	@param:		None
 * 	@retval:	None
 */
void getbutton1Value(void) {
	button1.key2 = button1.key1;
	button1.key1 = button1.key0;
	button1.key0 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if (button1.key2 == button1.key1 && button1.key1 == button1.key0) {
		if (button1.key2 != button1.oldState) {
			button1.oldState = button1.key2;
			if (button1.key2 == PRESSED) {
				button1.flag = 1;
			}
		}
		else {
			// Maybe long press, not need to handle
		}
	}
}

/**
 * 	@brief:		Handles debounce logic for button2
 *	@param:		None
 * 	@retval:	None
 */
void getbutton2Value(void) {
	button2.key2 = button2.key1;
	button2.key1 = button2.key0;
	button2.key0 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	if (button2.key2 == button2.key1 && button2.key1 == button2.key0) {
		if (button2.key2 != button2.oldState) {
			button2.oldState = button2.key2;
			if (button2.key2 == PRESSED) {
				button2.flag = 1;
			}
		}
		else {
			// Maybe long press, not need to handle
		}
	}
}

/**
 * 	@brief:		Handles debounce logic for button3
 *	@param:		None
 * 	@retval:	None
 */
void getbutton3Value(void) {
	button3.key2 = button3.key1;
	button3.key1 = button3.key0;
	button3.key0 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
	if (button3.key2 == button3.key1 && button3.key1 == button3.key0) {
		if (button3.key2 != button3.oldState) {
			button3.oldState = button3.key2;
			if (button3.key2 == PRESSED) {
				button3.flag = 1;
			}
		}
		else {
			// Maybe long press, not need to handle
		}
	}
}

/**
 * 	@brief:		Checks if button1 has been pressed and clears its flag
 *	@param:		None
 * 	@retval:	1 if button1 is pressed, 0 otherwise
 */
int isButton1Pressed(void) {
	if (button1.flag == 1) {
		button1.flag = 0;
		return 1;
	}
	else return 0;
}

/**
 * 	@brief:		Checks if button2 has been pressed and clears its flag
 *	@param:		None
 * 	@retval:	1 if button2 is pressed, 0 otherwise
 */
int isButton2Pressed(void) {
	if (button2.flag == 1) {
		button2.flag = 0;
		return 1;
	}
	else return 0;
}

/**
 * 	@brief:		Checks if button3 has been pressed and clears its flag
 *	@param:		None
 * 	@retval:	1 if button3 is pressed, 0 otherwise
 */
int isButton3Pressed(void){
	if (button3.flag == 1){
		button3.flag = 0;
		return 1;
	}
	else return 0;
}

/**
 * 	@brief:		Get value of 3 buttons
 *	@param:		None
 * 	@retval:	None
 */
void getButtonValue(void){
	getbutton1Value();
	getbutton2Value();
	getbutton3Value();
}


