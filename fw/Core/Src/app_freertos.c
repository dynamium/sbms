/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cell_monitor.h"
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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for cellMonitor */
osThreadId_t cellMonitorHandle;
const osThreadAttr_t cellMonitor_attributes = {
  .name = "cellMonitor",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 128 * 4
};
/* Definitions for statusLED */
osThreadId_t statusLEDHandle;
const osThreadAttr_t statusLED_attributes = {
  .name = "statusLED",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for chargeMonitor */
osThreadId_t chargeMonitorHandle;
const osThreadAttr_t chargeMonitor_attributes = {
  .name = "chargeMonitor",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 128 * 4
};
/* Definitions for canHandler */
osThreadId_t canHandlerHandle;
const osThreadAttr_t canHandler_attributes = {
  .name = "canHandler",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for currentMonitor */
osThreadId_t currentMonitorHandle;
const osThreadAttr_t currentMonitor_attributes = {
  .name = "currentMonitor",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartCellMonitorTask(void *argument);
void StartStatusLEDTask(void *argument);
void StartChargeMonitorTask(void *argument);
void StartCANHandlerTask(void *argument);
void StartCurrentMonitorTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of cellMonitor */
  cellMonitorHandle = osThreadNew(StartCellMonitorTask, NULL, &cellMonitor_attributes);

  /* creation of statusLED */
  statusLEDHandle = osThreadNew(StartStatusLEDTask, NULL, &statusLED_attributes);

  /* creation of chargeMonitor */
  chargeMonitorHandle = osThreadNew(StartChargeMonitorTask, NULL, &chargeMonitor_attributes);

  /* creation of canHandler */
  canHandlerHandle = osThreadNew(StartCANHandlerTask, NULL, &canHandler_attributes);

  /* creation of currentMonitor */
  currentMonitorHandle = osThreadNew(StartCurrentMonitorTask, NULL, &currentMonitor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartCellMonitorTask */
/**
  * @brief  Function implementing the cellMonitor thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartCellMonitorTask */
void StartCellMonitorTask(void *argument)
{
  /* USER CODE BEGIN StartCellMonitorTask */
  cellMonitorTask();
  /* USER CODE END StartCellMonitorTask */
}

/* USER CODE BEGIN Header_StartStatusLEDTask */
/**
* @brief Function implementing the statusLED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartStatusLEDTask */
void StartStatusLEDTask(void *argument)
{
  /* USER CODE BEGIN StartStatusLEDTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartStatusLEDTask */
}

/* USER CODE BEGIN Header_StartChargeMonitorTask */
/**
* @brief Function implementing the chargeMonitor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartChargeMonitorTask */
void StartChargeMonitorTask(void *argument)
{
  /* USER CODE BEGIN StartChargeMonitorTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartChargeMonitorTask */
}

/* USER CODE BEGIN Header_StartCANHandlerTask */
/**
* @brief Function implementing the canHandler thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCANHandlerTask */
void StartCANHandlerTask(void *argument)
{
  /* USER CODE BEGIN StartCANHandlerTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCANHandlerTask */
}

/* USER CODE BEGIN Header_StartCurrentMonitorTask */
/**
* @brief Function implementing the currentMonitor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCurrentMonitorTask */
void StartCurrentMonitorTask(void *argument)
{
  /* USER CODE BEGIN StartCurrentMonitorTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCurrentMonitorTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

