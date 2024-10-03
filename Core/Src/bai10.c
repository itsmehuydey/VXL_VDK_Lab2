/*
 * bai2.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include <bai10.h>

int counterMatrixLED_FLAG = 0;
int row = -1;;
int TIMER_CYCLE = 10;
int timer2_counter =0;
int timer2_flag = 0;
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
int shiftVar=0;

uint8_t matrix_buffer[8] = {
		0x18,0x3c,0x66,0xc3,0xff,0xff,0xc3,0xc3
};

void setTimer2(int duration){
	timer2_counter = duration  / 10;
	timer2_flag = 0;
}

void timer_run(){
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter == 0) timer2_flag = 1;
	}
}

GPIO_PinState convertToBit(uint8_t hexa, int index) {
    return (hexa & (1 << (15 - index - shiftVar))) ? SET : RESET;
}

void updateMatrix (int rowMatrixLed){
switch (rowMatrixLed) {
    case 0:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
        break;
    case 1:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
        break;
    case 2:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
        break;
    case 3:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
        break;
    case 4:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
        break;
    case 5:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
        break;
    case 6:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
        break;
    case 7:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
        break;
    default:
        break;
}
}

void updateLEDMatrix(int rowMatrixLed) {
    uint8_t rowData = matrix_buffer[rowMatrixLed];
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(rowData, 4));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(rowData, 5));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(rowData, 6));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(rowData, 7));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(rowData, 8));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(rowData, 9));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(rowData, 10));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(rowData, 11));
}
