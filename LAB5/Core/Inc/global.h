/*
 * global.h
 *
 *  Created on: Nov 27, 2025
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"

#define MAX_BUFFER_SIZE 30
#define IDLE 0
#define SEND_ADC 1
#define WAIT_OK 2

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t command_flag;
extern uint32_t ADC_value;


#endif
