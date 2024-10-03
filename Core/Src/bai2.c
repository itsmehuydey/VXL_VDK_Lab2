/*
 * bai2.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "bai2.h"

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

void update4seg (int num){
    switch (num) {
        case 0:
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
            display7SEG(1);
            break;
        case 1:
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
        	display7SEG(2);
            break;

        case 2:
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
            display7SEG(3);
            break;
        case 3:
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
            display7SEG(0);
            break;
        case 4:
        	default:
            break;
    }
}
