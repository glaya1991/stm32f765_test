#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tim.h"
#include "usart.h"

#include "Handler.h"
#include "ExtFunctions.h"
#include "LogModule.h"
#include "InOutBuffer.h"


int TransferUDP(
    const uint8_t *data,
    const uint32_t datalen,
    const char *address,
    const uint32_t port )
{
    return 0;
}

int TransferDMA(const uint8_t *data, uint32_t datalen)
{
    if ((data[0] == 1) && (data[1] == 28) && (data[2] == 32))
//        HAL_UART_Transmit(&huart1, (uint8_t *)data, datalen, 10000);
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)data, datalen);
    else
    {
        datalen = PacketizeInfo((uint8_t *)data, datalen, BUFFER_INOUT);
//        HAL_UART_Transmit(&huart1, (uint8_t *)data, datalen, 10000);
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)data, datalen);
    }
    return 0;
}

void AcquireCriticalResource(void)
{
    __disable_irq();
}

void ReleaseCriticalResource(void)
{
    __enable_irq();
}

void UserOperationHandler(void)
{
    int k = 0, l = 0;
    l = GetCnt();
    if ( ReadMem(REG_EEG_Auto_Band) > 0 )
    {
        if( ReadMem(REG_EEG_PocketSize) <= l )
        {
            l = GetDataReadyCnt(ReadMem(REG_EEG_PocketSize), (int32_t *)scratch_raw);
            if(l > 0)
            {
                if( ( k = Packetize(
                    (uint8_t *)scratch_raw,
                    (l * 4), 
                    4096) ) > 0 )
                {
                    TransferBand( (uint8_t *)scratch_raw, k );
                }
            }
        }
    }
    if ( ReadMem(REG_ADC_REG14) > 0 )
    {
        switch (ReadMem(REG_ADC_REG14)) 
        {
            case 1:
                AD7190_ContinuousReadStart();
//                AD7190_ChannelSelect(ReadMem(REG_ADC_REG3));
                break;
            case 2:
//                AD7190_Init();
//                HAL_NVIC_SystemReset();
                break;
            default:
                break;
        }
        WriteMem(REG_ADC_REG14,0);
    }
    OperationHandler();
}

void UserProtocolHandler(void)
{
    ProtocolHandler();
    return;
}

int32_t ADC_read_data_c(void)
{
    if (ReadMem(REG_EEG_File) == 0)
    {
        WriteMem(REG_ADC_CH1, 0);
        WriteMem(REG_ADC_CH2, 0);
        WriteMem(REG_ADC_CH3, 0);
        WriteMem(REG_ADC_CH4, 0);
        WriteMem(REG_ADC_CH5, 0);
        WriteMem(REG_ADC_CH6, 0);
        WriteMem(REG_ADC_CH7, 0);
        WriteMem(REG_ADC_CH8, 0);
    }
    return 0;
}

void SetLeds(uint8_t q_green, uint8_t q_red, uint8_t q_blue)
{
    if (q_green)
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
    if (q_red)
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
    if (q_blue)
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
    return;
}

int WriteBlock(char *namepart)
{
    return 0;
}

int ReadBlock(char *namepart)
{
    return 0;
}
void FormUpdateFile(int type, int ind_i) 
{
    return;
}
