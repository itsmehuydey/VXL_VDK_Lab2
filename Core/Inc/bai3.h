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
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];
extern int counter7Seg;

 void display7SEG(int number);
 void update7SEG(int index);
#endif /* INC_BAI2_H_ */
