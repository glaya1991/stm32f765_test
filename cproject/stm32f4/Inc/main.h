/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define AFE_SW_RESET_Pin GPIO_PIN_9
#define AFE_SW_RESET_GPIO_Port GPIOI
#define SPI5_CS_Pin GPIO_PIN_6
#define SPI5_CS_GPIO_Port GPIOF
#define SPI5_INT_Pin GPIO_PIN_10
#define SPI5_INT_GPIO_Port GPIOF
#define SPI5_INT_EXTI_IRQn EXTI15_10_IRQn
#define IrDA_RST_Pin GPIO_PIN_0
#define IrDA_RST_GPIO_Port GPIOC
#define IrDA_MODE_Pin GPIO_PIN_1
#define IrDA_MODE_GPIO_Port GPIOC
#define IrDA_BAUD2_Pin GPIO_PIN_2
#define IrDA_BAUD2_GPIO_Port GPIOC
#define IrDA_EN_Pin GPIO_PIN_3
#define IrDA_EN_GPIO_Port GPIOC
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define SPI1_SYNC_Pin GPIO_PIN_4
#define SPI1_SYNC_GPIO_Port GPIOC
#define SPI1_SYNC_EXTI_IRQn EXTI4_IRQn
#define SPI1_ADR_Pin GPIO_PIN_5
#define SPI1_ADR_GPIO_Port GPIOC
#define SPI6_CS_Pin GPIO_PIN_8
#define SPI6_CS_GPIO_Port GPIOG
#define WiFi_HIB_Pin GPIO_PIN_13
#define WiFi_HIB_GPIO_Port GPIOH
#define WiFi_SEL_Pin GPIO_PIN_14
#define WiFi_SEL_GPIO_Port GPIOH
#define WiFi_RST_Pin GPIO_PIN_15
#define WiFi_RST_GPIO_Port GPIOH
#define SPI2_CS_Pin GPIO_PIN_0
#define SPI2_CS_GPIO_Port GPIOI
#define SPI3_CS_Pin GPIO_PIN_15
#define SPI3_CS_GPIO_Port GPIOA
#define WiFi_INT_Pin GPIO_PIN_2
#define WiFi_INT_GPIO_Port GPIOD
#define WiFi_INT_EXTI_IRQn EXTI2_IRQn

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
