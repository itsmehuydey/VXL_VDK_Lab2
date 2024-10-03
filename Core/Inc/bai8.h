/*
 * bai2.h
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "main.h"
#ifndef INC_BAI2_H_
#define INC_BAI2_H_
extern int timer0_counter ;
extern int timer0_flag ;
extern int timer1_counter ;
extern int timer1_flag ;
extern int second;
extern int minute;
extern int hour;
extern const int MAX_LED;
extern int index_led, cnt;
extern int led_buffer[4];
 void display7SEG(int number);
 void updateClockBuffer();
 void update7SEG ( int index );
 void setTimer0(int duration);
 void setTimer1(int duration);
 void timerRun();
#endif /* INC_BAI2_H_ */
