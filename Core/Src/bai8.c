/*
 * bai2.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include <bai8.h>


int hour = 21 , minute = 10 , second = 55;
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_counter = 0;
int timer1_flag = 0;
int TIMER_CYCLE	= 10;
const int MAX_LED = 4;
int led_buffer [4] = {1 , 2 , 3 , 4};
int index_led = 0, cnt=0;

void setTimer0(int duration){
	timer0_counter = duration  / TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration  / TIMER_CYCLE;
	timer1_flag = 0;
}
void timerRun(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
}

void update7SEG ( int index ) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
    switch (index) {
        case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			display7SEG(led_buffer[index]);
            break ;
        case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			display7SEG(led_buffer[index]);
        	break ;
        case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			display7SEG(led_buffer[index]);
        	break ;
        case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display7SEG(led_buffer[index]);
            break ;
        default :
            break ;
    }
}

void updateClockBuffer (){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute%10;
 }

void display7SEG(int number)
{
    HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, SET);
    HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, SET);
    HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, SET);
    HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, SET);
    HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, SET);
    HAL_GPIO_WritePin(seg5_GPIO_Port, seg5_Pin, SET);
    HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, SET);
    switch (number)
    {
        case 0:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, RESET);
            HAL_GPIO_WritePin(seg5_GPIO_Port, seg5_Pin, RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg5_GPIO_Port, seg5_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg5_GPIO_Port, seg5_Pin, RESET);
            HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            break;
        case 8:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg5_GPIO_Port, seg5_Pin, RESET);
            HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg3_GPIO_Port, seg3_Pin, RESET);
            HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, RESET);
            HAL_GPIO_WritePin(seg2_GPIO_Port, seg2_Pin, RESET);
            HAL_GPIO_WritePin(seg7_GPIO_Port, seg7_Pin, RESET);
            break;
    }
}


