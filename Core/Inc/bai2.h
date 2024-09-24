/*
 * bai2.h
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "main.h"
#ifndef INC_BAI2_H_
#define INC_BAI2_H_
extern int counter7Seg;
extern int counterDot;
extern int currentIndex7Seg;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
 void display7SEG(int number);
// void clearNumber();

#endif /* INC_BAI2_H_ */
