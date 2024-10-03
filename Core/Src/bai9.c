/*
 * bai2.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include <bai9.h>

int counterMatrixLED_FLAG = 0;
int row = -1;
int TIMER_CYCLE = 10;
const int MAX = 8;
int current = 0;
int timer2_counter =0;
int timer2_flag = 0;

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

void updateMatrix(int row){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
                           GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, RESET);
    switch (row) {
        case 0:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
            break;
        default:
            break;
    }
}

GPIO_PinState convertToBit(uint8_t hexa, int index) {
    return (hexa & (1 << (7 - index))) ? SET : RESET;
}

typedef uint8_t MatrixBuffer[8];
MatrixBuffer matrix_buffers[3] = {
    {0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xc3, 0xc3}, // H
    {0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7e}, // u
    {0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18, 0x18, 0x18}  // y
};

void updateLEDMatrix(int row) {
    uint8_t rowData = matrix_buffers[current ][row];
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(rowData, 0));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(rowData, 1));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(rowData, 2));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(rowData, 3));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(rowData, 4));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(rowData, 5));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(rowData, 6));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(rowData, 7));
}
