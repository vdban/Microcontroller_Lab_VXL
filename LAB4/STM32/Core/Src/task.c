/*
 * task.c
 *
 *  Created on: Nov 13, 2025
 *      Author: ACER
 */

#include<task.h>
#include<main.h>
// Task 1
void Task1_ToggleLed(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

// Task 2
void Task2_ToggleLed(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
}

// Task 3
void Task3_ToggleLed(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
}

// Task 4
void Task4_ToggleLed(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
}

// Task 5
void Task5_ToggleLed(void) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
}
