/*
 * bai2.h
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "main.h"
#ifndef INC_BAI2_H_
#define INC_BAI2_H_
extern const int MAX_LED ;
extern int index_led;
extern int led_buffer [4] ;
extern int hour , minute , second;
extern int timer0_counter;
extern int timer0_flag;
extern int timer1_counter;
extern int timer1_flag;
extern int TIMER_CYCLE;
extern int cnt, index_led;
 void display7SEG(int number);
 void updateClockBuffer();
 void update7SEG ( int index );
 void setTimer0(int duration);
 void setTimer1(int duration);
 void timerRun();
#endif /* INC_BAI2_H_ */
