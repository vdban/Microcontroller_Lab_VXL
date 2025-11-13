/*
 * display_7seg.c
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#include "fsm_automatic.h"
#include "fsm_setting.h"
#include "main.h"
#include "display_7seg.h"
#include "software_timer.h"

/**
 * 	@brief:		Display number to 7 SEG led with prior buffer
 *	@param:		None
 * 	@retval:	None
 */
void displaySegment(void){
	/**
	 * Switch between the states of the 7-segment LED display.
	 * - INIT: Initialize the display and set the timer.
	 * - SEG0 to SEG3: Enable the corresponding segment and display the number.
	 * Transition between segments occurs when timer2_flag is set.
	 */
	switch (STATUS_7SEG) {
		case INIT:
			STATUS_7SEG = SEG0;
			setTimer2(TIME_7SEG);
			break;
		case SEG0:
			setEnableSignal(SEG0);
			displayNumber(led_buffer[SEG0]);
			if (timer2_flag == 1) {
				STATUS_7SEG = SEG1;
				setTimer2(TIME_7SEG);
			}
			break;
		case SEG1:
			setEnableSignal(SEG1);
			displayNumber(led_buffer[SEG1]);
			if (timer2_flag == 1) {
				STATUS_7SEG = SEG2;
				setTimer2(TIME_7SEG);
			}
			break;
		case SEG2:
			setEnableSignal(SEG2);
			displayNumber(led_buffer[SEG2]);
			if (timer2_flag == 1) {
				STATUS_7SEG = SEG3;
				setTimer2(TIME_7SEG);
			}
			break;
		case SEG3:
			setEnableSignal(SEG3);
			displayNumber(led_buffer[SEG3]);
			if (timer2_flag == 1) {
				STATUS_7SEG = SEG0;
				setTimer2(TIME_7SEG);
			}
			break;
		default:
			break;
	}
}

/**
 * 	@brief:		Activate the enable 7-segment LED
 *	@param:		Index of the 7-segment LED to activate (from 0 to 4)
 * 	@retval:	None
 */
void setEnableSignal(int index){
	switch (index){
	case SEG0:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  break;
	case SEG1:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  break;
	case SEG2:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  break;
	case SEG3:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		  break;
	default:
		break;
	}
}

/**
 * 	@brief:		Display a number on 7-segment LED
 *	@param:		Number to display (from 0 to 9)
 * 	@retval:	None
 */
void displayNumber(int num){
	 switch (num)
	 {
	 case 0:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);
		 break;
	 case 1:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);
		 break;
	 case 2:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 3:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 4:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 5:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 6:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 7:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);
		 break;
	 case 8:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 case 9:
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
		 break;
	 default:
		 break;
	 }
}

/**
 * 	@brief:		Update buffer based on the selected mode (MODE2, MODE3 and MODE4)
 *	@param:		Mode to update the LED buffer
 * 	@retval:	None
 */
void updateBufferWithMode(int MODE) {
	switch(MODE) {
		case MODE2:
			led_buffer[0] = valueSetting / 10;
			led_buffer[1] = valueSetting % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 2;
			break;
		case MODE3:
			led_buffer[0] = valueSetting / 10;
			led_buffer[1] = valueSetting % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 3;
			break;
		case MODE4:
			led_buffer[0] = valueSetting / 10;
			led_buffer[1] = valueSetting % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 4;
			break;
		default:
			break;
	}
}
