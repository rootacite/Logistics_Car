/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define INDUCTION_BESIDE_2_Pin GPIO_PIN_3
#define INDUCTION_BESIDE_2_GPIO_Port GPIOE
#define INDUCTION_BESIDE_3_Pin GPIO_PIN_4
#define INDUCTION_BESIDE_3_GPIO_Port GPIOE
#define INDUCTION_BESIDE_4_Pin GPIO_PIN_5
#define INDUCTION_BESIDE_4_GPIO_Port GPIOE
#define INDUCTION_BESIDE_5_Pin GPIO_PIN_6
#define INDUCTION_BESIDE_5_GPIO_Port GPIOE
#define INDUCTION_FRONT_1_Pin GPIO_PIN_13
#define INDUCTION_FRONT_1_GPIO_Port GPIOC
#define INDUCTION_FRONT_5_Pin GPIO_PIN_0
#define INDUCTION_FRONT_5_GPIO_Port GPIOF
#define INDUCTION_FRONT_4_Pin GPIO_PIN_1
#define INDUCTION_FRONT_4_GPIO_Port GPIOF
#define INDUCTION_FRONT_3_Pin GPIO_PIN_2
#define INDUCTION_FRONT_3_GPIO_Port GPIOF
#define INDUCTION_FRONT_2_Pin GPIO_PIN_3
#define INDUCTION_FRONT_2_GPIO_Port GPIOF
#define FRONT_CLK_Pin GPIO_PIN_1
#define FRONT_CLK_GPIO_Port GPIOA
#define BEHIDE_CLK_Pin GPIO_PIN_2
#define BEHIDE_CLK_GPIO_Port GPIOA
#define LEFT_CLK_Pin GPIO_PIN_3
#define LEFT_CLK_GPIO_Port GPIOA
#define FRONT_DIR_Pin GPIO_PIN_13
#define FRONT_DIR_GPIO_Port GPIOF
#define BEHIED_DIR_Pin GPIO_PIN_14
#define BEHIED_DIR_GPIO_Port GPIOF
#define LEFT_DIR_Pin GPIO_PIN_15
#define LEFT_DIR_GPIO_Port GPIOF
#define RIGHT_DIR_Pin GPIO_PIN_0
#define RIGHT_DIR_GPIO_Port GPIOG
#define BEHIED_EN_Pin GPIO_PIN_12
#define BEHIED_EN_GPIO_Port GPIOD
#define LEFT_EN_Pin GPIO_PIN_13
#define LEFT_EN_GPIO_Port GPIOD
#define RIGHT_EN_Pin GPIO_PIN_6
#define RIGHT_EN_GPIO_Port GPIOC
#define FRONT__EN_Pin GPIO_PIN_8
#define FRONT__EN_GPIO_Port GPIOB
#define RIGHT_CLK_Pin GPIO_PIN_9
#define RIGHT_CLK_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
