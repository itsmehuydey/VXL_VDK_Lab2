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
int currentBuffer = 0;


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

void updateMatrix(int rowMatrixLed){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
                           GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, RESET);
    switch (rowMatrixLed) {
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

void updateLEDMatrix(int rowMatrixLed) {
    uint8_t rowData = matrix_buffers[currentBuffer ][rowMatrixLed];
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, convertToBit(rowData, 0));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, convertToBit(rowData, 1));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, convertToBit(rowData, 2));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, convertToBit(rowData, 3));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, convertToBit(rowData, 4));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, convertToBit(rowData, 5));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, convertToBit(rowData, 6));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, convertToBit(rowData, 7));
}


//void updateLEDMatrix(int rowMatrixLed) {
//    uint8_t rowData = matrix_buffers[currentBuffer][rowMatrixLed];
//    uint16_t gpio_pins[] = {GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};
//    for (int i = 0; i < 8; i++) {
//        HAL_GPIO_WritePin(GPIOA, gpio_pins[i], convertToBit(rowData, i));
//    }
//}

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
  setTimer2(500);
//  displayA();
    while (1)
    {
    	/* USER CODE BEGIN 3 */
    	if (timer2_flag == 1) {
    		++rowMatrixLed;
    	        if(rowMatrixLed>= MAX_LED_MATRIX) {
    	        	rowMatrixLed=0;
    	        	currentBuffer = (currentBuffer + 1) % 3;
    	        }
    	        rowMatrixLed = rowMatrixLed % MAX_LED_MATRIX;
    	        updateMatrix(rowMatrixLed);
    	        updateLEDMatrix(rowMatrixLed);
    	        setTimer2(500);
    	        timer2_flag = 0;
    	    }

     /* USER CODE BEGIN 3 */


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
