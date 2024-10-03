/*
 * bai2.h
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "main.h"
#ifndef INC_BAI2_H_
#define INC_BAI2_H_
extern int counterMatrixLED_FLAG ;
extern int row ;
extern int TIMER_CYCLE;
extern int timer2_counter;
extern int timer2_flag ;
extern const int MAX ;
extern int current ;

void setTimer2(int duration);
void timer_run();
void updateMatrix(int row);
GPIO_PinState convertToBit(uint8_t hexa, int index);
void updateLEDMatrix(int row);
#endif /* INC_BAI2_H_ */
