/*
 * bai2.c
 *
 *  Created on: Sep 23, 2024
 *      Author: pc
 */
#include "bai2.h"

int counter7Seg = 50;
int counterDot = 100;
int currentIndex7Seg = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (counter7Seg <= 0) {
        counter7Seg = 50;

        // Turn off the current segment before switching to the next
        switch (currentIndex7Seg) {
            case 0:
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); // TURN OFF SEG 0
                display7SEG(2); // Display number 2 on the 7-segment
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7); // TURN ON SEG 1
                ++currentIndex7Seg;
                break;

            case 1:
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7); // TURN OFF SEG 1
                display7SEG(3); // Display number 3 on the 7-segment
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); // TURN ON SEG 2
                ++currentIndex7Seg;
                break;

            case 2:
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); // TURN OFF SEG 2
                display7SEG(0); // Display number 0 on the 7-segment
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9); // TURN ON SEG 3
                ++currentIndex7Seg;
                break;

            case 3:
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9); // TURN OFF SEG 3
                display7SEG(1); // Display number 1 on the 7-segment
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); // TURN ON SEG 0
                currentIndex7Seg = 0;
                break;

            default:
                break;
        }
    } else {
        --counter7Seg;
    }

    // Handle dot blinking
    if (counterDot <= 0) {
        counterDot = 100;
        HAL_GPIO_TogglePin(GPIOA, DOT_Pin); // Toggle the dot
    } else {
        --counterDot;
    }
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
