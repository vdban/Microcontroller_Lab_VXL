/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#include "fsm_automatic.h"
#include "software_timer.h"
#include "main.h"
#include "display_7seg.h"

/*	@brief:		All the LED of system off
 *	@param:		None
 * 	@retval:	None
 */
void allLEDoff() {
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin
							|LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin, SET);
}

/*	@brief:		Traffic light run automatically (Mode 1)
 *	@param:		None
 * 	@retval:	None
 */
void fsm_automatic() {
	switch (autoStatus) {
	case INIT:
		allLEDoff();
		autoStatus = RED_GREEN;
		count = timeGreen;
		setTimer1(1000);
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_GREEN_2_Pin, RESET);
		led_buffer[0] = (count + timeYellow) / 10;
		led_buffer[1] = (count + timeYellow) % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (timer1_flag == 1) {
			setTimer1(1000);
			count--;
			if (count <= 0) {
				autoStatus = RED_YELLOW;
				count = timeYellow;
				allLEDoff();
			}
		}
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (timer1_flag == 1) {
			setTimer1(1000);
			count--;
			if (count <= 0) {
				autoStatus = GREEN_RED;
				count = timeGreen;
				allLEDoff();
			}
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_RED_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = (count + timeYellow) / 10;
		led_buffer[3] = (count + timeYellow) % 10;
		if (timer1_flag == 1) {
			setTimer1(1000);
			count--;
			if (count <= 0) {
				autoStatus = YELLOW_RED;
				count = timeYellow;
				allLEDoff();
			}
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_YELLOW_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (timer1_flag == 1) {
			setTimer1(1000);
			count--;
			if (count <= 0) {
				autoStatus = RED_GREEN;
				count = timeGreen;
				allLEDoff();
			}
		}
		break;
	default:
		break;
	}
}
