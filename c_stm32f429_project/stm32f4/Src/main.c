/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* USER CODE BEGIN Includes */
#include "Handler.h"
#include "ExtFunctions.h"
#include "AD7190.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint8_t usart1BufRx[1];
uint8_t I2C2_TRANSMIT_STARTED = 0;
uint8_t I2C2_TRANSMIT_ENDED = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_UART4_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_SPI3_Init();
  MX_SPI5_Init();
  MX_SPI6_Init();
  MX_TIM14_Init();
  MX_TIM13_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_I2C3_Init();
  MX_FMC_Init();
  MX_TIM7_Init();
  MX_TIM10_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
    SPI6_CS_UP
    InitHandler(POLYGRAPH);
    EEGRecorderInit(1,250);
    WriteMem(REG_LOG_LVL, 7);
    WriteMem(REG_Simple_link, 1);
    WriteMem(REG_EEG_Auto_Band, 0);
    WriteMem(REG_ADC_REG1,0x00000001);
    WriteMem(REG_ADC_REG2,0x00000001);
    WriteMem(REG_ADC_REG3,0x00000004);
    usart1BufRx[0] = 0x00;
    HAL_UART_Receive_DMA(&huart1, usart1BufRx, 1);
    HAL_TIM_Base_Start_IT(&htim7);
    HAL_TIM_Base_Start_IT(&htim10);
    HAL_TIM_Base_Start_IT(&htim11);

//    AD7190_Reset();
    unsigned long samplesAverage = 0x0;
    unsigned long chn = 0x0;
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_STAT, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_STAT %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_MODE, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_MODE %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_CONF, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_CONF %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_DATA %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_ID, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_ID %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_GPOCON, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_GPOCON %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_OFFSET, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_OFFSET %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_FULLSCALE, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_FULLSCALE %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
    
//    AD7190_SetPower(1);
    if (AD7190_Init() == 1)
    {
        AD7190_SetLeds(2);
        HAL_UART_Transmit(&huart1, "AD7190 found", 12, 10000);
    }
    else
    {
        AD7190_SetLeds(0);
        HAL_UART_Transmit(&huart1, "AD7190 not found", 16, 10000);
    }
//    HAL_SPI_Transmit_DMA(&hspi1, "-----", 5);
//    AD7190_RangeSetup(1,AD7190_CONF_GAIN_1);
//    AD7190_ChannelSelect(AD7190_CH_AIN1P_AINCOM);
//    CommandLineInterpreter("/get/memory?ip=192.168.1.3&port=5683");
    
//        HAL_UART_Transmit(&huart1, "test2", 5, 10000);
    WriteMem(REG_Led_Ch_T1,1);
    WriteMem(REG_Led_Ch_T2,2);
    WriteMem(REG_Led_Ch_T3,4);
    WriteMem(REG_Led_Q_T1_Red,100);
    WriteMem(REG_Led_Q_T1_Green,1);
    WriteMem(REG_Led_Q_T1_Blue,1);
    WriteMem(REG_Led_Q_T2_Red,1);
    WriteMem(REG_Led_Q_T2_Green,100);
    WriteMem(REG_Led_Q_T2_Blue,1);
    WriteMem(REG_Led_Q_T3_Red,1);
    WriteMem(REG_Led_Q_T3_Green,1);
    WriteMem(REG_Led_Q_T3_Blue,100);
    
    AFE_MUX_IMP_init();
    
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//    AD7190_GetRegisterValue(AD7190_REG_ID, 1, 1, 0);
//    initiateConversionCycle();
//    HAL_SPI_Transmit_DMA(&hspi1, "-----", 5);
//    initiateDMATestCycle();
//    AD7190_SetLeds(2);
    AD7190_ContinuousReadStart();
    unsigned char i=0;
//    HAL_UART_Transmit(&huart1, "Check", 5, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_STAT, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_STAT %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_MODE, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_MODE %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_CONF, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_CONF %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_DATA %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_ID, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_ID %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_GPOCON, 1, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_GPOCON %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_OFFSET, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_OFFSET %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
//    HAL_Delay(1000);
//    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_FULLSCALE, 3, 1, 1); 
//    chn=sprintf(buffer,"AD7190_REG_FULLSCALE %08X",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000); 
    
    HAL_Delay(3000);
    HAL_TIM_Base_Start_IT(&htim14);
    HAL_UART_Transmit(&huart1, "\n\r\nStart!\n\r\n", 12, 1000);
    while (1)
    {
      UserOperationHandler();
      UserProtocolHandler();
      
//      if (observerConversionCycle())
//        initiateConversionCycle();
       
      
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
//    WriteMem(REG_ADC_CH1,AD7190_ContinuousRead());
    }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance == I2C2)
	{
		I2C2_TRANSMIT_ENDED = 1;
	}
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance == I2C2)
	{
		I2C2_TRANSMIT_ENDED = 1;
	}
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance == I2C2)
	{
		I2C2_TRANSMIT_ENDED = 1;
	}
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance == I2C2)
	{
		I2C2_TRANSMIT_ENDED = 1;
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM13)
	{
		AFEMUX_timer_callback();
	}

	if(htim->Instance == TIM14)
	{
		//IMP_timer_callback();
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
//  while(1) 
//  {
//  }
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/