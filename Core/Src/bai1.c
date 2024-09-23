/*
 * bai1.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "Bai1.h"
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
