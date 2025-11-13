/*
 * task.c
 *
 *  Created on: Nov 13, 2025
 *      Author: ACER
 */

#include "main.h"
#include "task.h"
#include "scheduler.h"


static sTask SCH_tasks_G[SCH_MAX_TASKS];
static uint32_t current_task_id = 0;

void SCH_Init(void) {
	current_task_id = 0;
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	uint32_t index = 0;

	while (index < SCH_MAX_TASKS && SCH_tasks_G[index].pTask != NULL) {
		index++;
	}

	if (index == SCH_MAX_TASKS) {
		// TODO:
		return SCH_MAX_TASKS;
	}

	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = 0;
	SCH_tasks_G[index].TaskID = current_task_id++;

	return SCH_tasks_G[index].TaskID;
}

uint8_t SCH_Delete_Task(uint32_t taskID) {
	uint8_t return_code = 0;
	uint32_t index = 0;

	while (index < SCH_MAX_TASKS && SCH_tasks_G[index].TaskID != taskID) {
		index++;
	}

	if (index < SCH_MAX_TASKS) {
		SCH_tasks_G[index].pTask = NULL;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
		SCH_tasks_G[index].TaskID = 0;
		return_code = 1;
	}

	return return_code;
}

void SCH_Update(void) {
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
		if (SCH_tasks_G[i].pTask != NULL) {
			if (SCH_tasks_G[i].Delay == 0) {
				SCH_tasks_G[i].RunMe += 1;
				if (SCH_tasks_G[i].Period > 0) {
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}
			} else {
				SCH_tasks_G[i].Delay -= 1;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			(*SCH_tasks_G[i].pTask)();
			SCH_tasks_G[i].RunMe -= 1;
			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Task(SCH_tasks_G[i].TaskID);
			}
		}
	}
}
