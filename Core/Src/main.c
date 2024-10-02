/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int counter7Seg_FLAG = 0;
int counter7Seg = 50; // 200 ms = 20 * 10 ms

int counterDot_FLAG = 0;
int counterDot = 100; // 1000 ms = 100 * 10 ms

int counterMatrixLED_FLAG = 0;
 // 100 ms = 10 * 10 ms
int rowMatrixLed = -1;

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

int hour = 15, minute = 8, second = 50;

int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;
int timer2_counter =0;
int timer2_flag = 0;
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;

// Ma trận LED để hiển thị chữ 'A'
uint8_t matrix_buffer[8] = {
//    0x18, // 00011000
//    0x24, // 00100100
//    0x42, // 01000010
//    0x42, // 01000010
//    0x7E, // 01111110
//    0x42, // 01000010
//    0x42, // 01000010
//    0x42  // 01000010

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
int shiftVar=0;
GPIO_PinState convertToBit(uint8_t hexa, int index) {
//    return (hexa & (1 << (7 - index))) ? SET : RESET;

	int arr[16];
	int arr_copy[16];

	for (int i = 15; i >= 0; --i) {
	    int mod = hexa % 2;
	    hexa = hexa / 2;
	    arr[i] = mod;
	    arr_copy[i] = mod;
	}

    for (int index = 0; index < 16; ++index) {
        int newIndex = index - shiftVar;
        if (newIndex >= 0) {
            arr[newIndex] = arr_copy[index];
        } else {
            arr[15 - shiftVar + 1] = arr_copy[index];
        }
    }

    if (arr[index] == 1) return SET;
    return RESET;
}

void updateLEDMatrix(int index) {
    switch(index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[0], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[0], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[0], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[0], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[0], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[0], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[0], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[0], 7));
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[1], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[1], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[1], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[1], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[1], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[1], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[1], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[1], 7));
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[2], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[2], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[2], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[2], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[2], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[2], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[2], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[2], 7));
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[3], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[3], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[3], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[3], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[3], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[3], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[3], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[3], 7));
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[4], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[4], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[4], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[4], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[4], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[4], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[4], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[4], 7));
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[5], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[5], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[5], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[5], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[5], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[5], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[5], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[5], 7));
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[6], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[6], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[6], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[6], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[6], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[6], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[6], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[6], 7));
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[7], 0));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[7], 1));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[7], 2));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[7], 3));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[7], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[7], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[7], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[7], 7));
            break;
        default:
            break;
    }
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

void updateLEDMatrix2(int index) {
    switch (index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[0], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[0], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[0], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[0], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[0], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[0], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[0], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[0], 11));
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[1], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[1], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[1], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[1], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[1], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[1], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[1], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[1], 11));
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[2], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[2], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[2], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[2], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[2], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[2], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[2], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[2], 11));
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[3], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[3], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[3], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[3], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[3], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[3], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[3], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[3], 11));
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[4], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[4], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[4], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[4], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[4], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[4], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[4], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[4], 11));
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[5], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[5], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[5], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[5], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[5], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[5], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[5], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[5], 11));
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[6], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[6], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[6], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[6], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[6], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[6], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[6], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[6], 11));
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(matrix_buffer[7], 4));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(matrix_buffer[7], 5));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(matrix_buffer[7], 6));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(matrix_buffer[7], 7));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(matrix_buffer[7], 8));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(matrix_buffer[7], 9));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(matrix_buffer[7], 10));
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(matrix_buffer[7], 11));
            break;
        default:
            break;
    }
}



void displayLEDMatrix(int num){
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, !(num & 0x01));
	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, !(num & 0x02));
	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, !(num & 0x04));
	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, !(num & 0x08));
	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, !(num & 0x10));
	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, !(num & 0x20));
	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, !(num & 0x40));
	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, !(num & 0x80));
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  	//Set timer for 7ledSeg
  setTimer2(500);
    while (1)
    {
    	/* USER CODE BEGIN 3 */
    	if (timer2_flag == 1) {
    		++rowMatrixLed;
    	        //rowMatrixLed = rowMatrixLed % MAX_LED_MATRIX;

    	         if( rowMatrixLed == 8) {
    	         shiftVar = ( shiftVar + 1) % 16;
    	         rowMatrixLed = rowMatrixLed % 8;
    	         }

    	         updateMatrix(rowMatrixLed);
    	         updateLEDMatrix2(rowMatrixLed);
    	        // displayLEDMatrix(rowMatrixLed);
    	        setTimer2(100);
    	        timer2_flag = 0;
    	    }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|Led_red_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, seg1_Pin|seg2_Pin|seg3_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|seg4_Pin|seg5_Pin|seg6_Pin
                          |seg7_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin Led_red_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|Led_red_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : seg1_Pin seg2_Pin seg3_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin seg4_Pin seg5_Pin seg6_Pin
                           seg7_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = seg1_Pin|seg2_Pin|seg3_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|seg4_Pin|seg5_Pin|seg6_Pin
                          |seg7_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    timer_run();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
