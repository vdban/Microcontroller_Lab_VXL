/*
 * global.c
 *
 *  Created on: Nov 14, 2024
 *      Author: HP
 */

#include "global.h"

int autoStatus = INIT;

int timeRed = 5;
int timeYellow = 2;
int timeGreen = 3;

int count = 0;

int FSM_STATUS = INIT;
int valueSetting = 0;
int BLINKY_LED_STATUS = INIT;

int led_buffer[4] = {0, 0, 0, 0};
int STATUS_7SEG = INIT;
int TIME_7SEG = 250; // The time of change to other 7-segment LED is 0.25 second
