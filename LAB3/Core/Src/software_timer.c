/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2024
 *      Author: HP
 */

#include "software_timer.h"

int TIME_CYCLE = 10;

// Timer 1 is used for traffic light (MODE 1)
int timer1_counter = 0;
int timer1_flag = 0;

// Timer 2 is used for setting the frequency of four 7-segment LEDs
int timer2_counter = 0;
int timer2_flag = 0;

// Timer 3 is used for the frequency of 7-segment LEDs when entering MODE 2 to MODE 4
int timer3_counter = 0;
int timer3_flag = 0;

void setTimer1(int duration) {
	timer1_counter = duration / TIME_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration) {
	timer2_counter = duration / TIME_CYCLE;
	timer2_flag = 0;
}

void setTimer3(int duration) {
	timer3_counter = duration / TIME_CYCLE;
	timer3_flag = 0;
}

void timer1Run(){
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}

void timer2Run(){
	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}
}

void timer3Run(){
	if (timer3_counter > 0) {
		timer3_counter--;
		if (timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}
}

void timerRun() {
	timer1Run();
	timer2Run();
	timer3Run();
}
