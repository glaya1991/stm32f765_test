#include "AD7190.h"
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************************************************//**
 *   @file   AD7190.c
 *   @brief  Implementation of AD7190 Driver.
********************************************************************************
 * Copyright 2012(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
********************************************************************************
 *   SVN Revision: 903
*******************************************************************************/

uint8_t buffer[20] = {0,0,0,0,0};
int st = 0;

#include "usart.h"
#include "spi.h"
#include "Handler.h"
inline unsigned char SPI_Read(unsigned char slaveDeviceId,
                       unsigned char* data,
                       unsigned char bytesNumber)
{
    if (bytesNumber > 5)
        return 1;
    buffer[0] = data[0];
    buffer[1] = 0x00;
    buffer[2] = 0x00;
    buffer[3] = 0x00;
    HAL_SPI_TransmitReceive(&hspi1, buffer, data, bytesNumber, 10000);
    return 0;
}
inline unsigned char SPI_Read_DMA(unsigned char slaveDeviceId,
                       unsigned char* data,
                       unsigned char bytesNumber)
{
    unsigned long timeOutCnt = 0xFFFFF;
    if (bytesNumber > 5)
        return 1;
    buffer[0] = data[0];
    buffer[1] = 0x00;
    buffer[2] = 0x00;
    buffer[3] = 0x00;
    while (((HAL_SPI_TransmitReceive_DMA(&hspi1, buffer, data, bytesNumber)) != HAL_OK) 
            && timeOutCnt--)//;
//    if (HAL_SPI_TransmitReceive_DMA(&hspi1, buffer, data, bytesNumber) != HAL_OK)
    {
      HAL_UART_Transmit(&huart1, ".", 1, 10000);
    }
    return 0;
}
inline unsigned char SPI_Write(unsigned char slaveDeviceId,
                        unsigned char* data,
                        unsigned char bytesNumber)
{
    if (bytesNumber > 20)
        return 1;
    buffer[0] = data[0];
    buffer[1] = data[1];
    buffer[2] = data[2];
    buffer[3] = data[3];
//    HAL_UART_Transmit(&huart1, buffer, bytesNumber, 10000);
    HAL_SPI_Transmit(&hspi1, buffer, bytesNumber, 10000);
    return 0;
}
inline unsigned char SPI_Write_DMA(unsigned char slaveDeviceId,
                        unsigned char* data,
                        unsigned char bytesNumber)
{
    unsigned long timeOutCnt = 0xFFFFF;
    if (bytesNumber > 5)
        return 1;
//    HAL_UART_Transmit(&huart1, "_DMA", 4, 10000);
    buffer[0] = data[0];
    buffer[1] = data[1];
    buffer[2] = data[2];
    buffer[3] = data[3];
    int herr;
//    HAL_SPI_Transmit_DMA(&hspi1, "-----", 5);
//    HAL_UART_Transmit(&huart1, buffer, bytesNumber, 10000);
    while (((HAL_SPI_Transmit_DMA(&hspi1, buffer, bytesNumber)) != HAL_OK) 
            && timeOutCnt--)//;
    {
      HAL_UART_Transmit(&huart1, "-", 1, 10000);
    }
//    if ((herr=HAL_SPI_Transmit_DMA(&hspi1, buffer, bytesNumber)) != HAL_OK)
//    {
//        if (herr == HAL_ERROR)
//            HAL_UART_Transmit(&huart1, "WDMA err", 8, 10000);
//        if (herr == HAL_BUSY)
//            HAL_UART_Transmit(&huart1, "WDMA bus", 8, 10000);
//        if (herr == HAL_TIMEOUT)
//            HAL_UART_Transmit(&huart1, "WDMA tim", 8, 10000);
//    }
//    HAL_SPI_Transmit_DMA(&hspi1, buffer, bytesNumber);
    return 0;
}
/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

/***************************************************************************//**
 * @brief Writes data into a register.
 *
 * @param registerAddress - Address of the register.
 * @param registerValue - Data value to write.
 * @param bytesNumber - Number of bytes to be written.
 * @param modifyCS - Allows Chip Select to be modified.
 *
 * @return none.
*******************************************************************************/
void AD7190_SetRegisterValue(unsigned char registerAddress,
                             unsigned long registerValue,
                             unsigned char bytesNumber,
                             unsigned char modifyCS,
                             unsigned char blockMode)
{
    unsigned char writeCommand[5] = {0, 0, 0, 0, 0};
    unsigned char* dataPointer    = (unsigned char*)&registerValue;
    unsigned char bytesNr         = bytesNumber;
    
    writeCommand[0] = AD7190_COMM_WRITE |
                      AD7190_COMM_ADDR(registerAddress);
    while(bytesNr > 0)
    {
        writeCommand[bytesNr] = *dataPointer;
        dataPointer ++;
        bytesNr --;
    }
    if (blockMode == 1)
        SPI_Write(AD7190_SLAVE_ID * modifyCS, writeCommand, bytesNumber + 1);
    else
        SPI_Write_DMA(AD7190_SLAVE_ID * modifyCS, writeCommand, bytesNumber + 1);
}

/***************************************************************************//**
 * @brief Reads the value of a register.
 *
 * @param registerAddress - Address of the register.
 * @param bytesNumber - Number of bytes that will be read.
 * @param modifyCS    - Allows Chip Select to be modified.
 *
 * @return buffer - Value of the register.
*******************************************************************************/
unsigned char non_block_registerWord[5] = {0, 0, 0, 0, 0}; 
unsigned long AD7190_GetRegisterValue(unsigned char registerAddress,
                                      unsigned char bytesNumber,
                                      unsigned char modifyCS,
                                      unsigned char blockMode)
{
    unsigned char registerWord[5] = {0, 0, 0, 0, 0}; 
    unsigned long buffer          = 0x0;
    unsigned char i               = 0;
    
    registerWord[0] = AD7190_COMM_READ |
                      AD7190_COMM_ADDR(registerAddress);
    if (blockMode)
        SPI_Read(AD7190_SLAVE_ID * modifyCS, registerWord, bytesNumber + 1);
    else
    {
        SPI_Read_DMA(AD7190_SLAVE_ID * modifyCS, registerWord, bytesNumber + 1);
        return 0;
    }
    for(i = 1; i < bytesNumber + 1; i++) 
    {
        buffer = (buffer << 8) + registerWord[i];
    }
    
    return buffer;
}

/***************************************************************************//**
 * @brief Checks if the AD7190 part is present.
 *
 * @return status - Indicates if the part is present or not.
*******************************************************************************/
unsigned char AD7190_Init(void)
{
    st = 0;
    unsigned char status = 1;
    unsigned char regVal = 0;
    unsigned char registerWord[5] = {0, 0, 0, 0, 0}; 
    
    _CS_H
    HAL_Delay(1);
    _CS_L
    HAL_Delay(1);
    AD7190_Reset();
    /* Allow at least 500 us before accessing any of the on-chip registers. */
    HAL_Delay(100);
//    SPI_Read(0x20, registerWord, 2);
    regVal = AD7190_GetRegisterValue(AD7190_REG_ID, 1, 1, 1);
    if( (regVal & AD7190_ID_MASK) != ID_AD7190)
    {
        status = 0;
    }
    HAL_Delay(1);
    _CS_H
    return status ;
}

/***************************************************************************//**
 * @brief Resets the device.
 *
 * @return none.
*******************************************************************************/
void AD7190_Reset(void)
{
    st = 0;
    unsigned char registerWord[10];
    
    registerWord[0] = 0x01;
    registerWord[1] = 0xFF;
    registerWord[2] = 0xFF;
    registerWord[3] = 0xFF;
    registerWord[4] = 0xFF;
    registerWord[5] = 0xFF;
    registerWord[6] = 0xFF;
    registerWord[7] = 0xFF;
    registerWord[8] = 0xFF;
    registerWord[9] = 0xFF;
    SPI_Write(AD7190_SLAVE_ID, registerWord, 10);
}

/***************************************************************************//**
 * @brief Set device to idle or power-down.
 *
 * @param pwrMode - Selects idle mode or power-down mode.
 *                  Example: 0 - power-down
 *                           1 - idle
 *
 * @return none.
*******************************************************************************/
void AD7190_SetPower(unsigned char pwrMode)
{
    st = 0;
     unsigned long oldPwrMode = 0x0;
     unsigned long newPwrMode = 0x0; 
 
     oldPwrMode = AD7190_GetRegisterValue(AD7190_REG_MODE, 3, 1, 1);
     oldPwrMode &= ~(AD7190_MODE_SEL(0x7));
     newPwrMode = oldPwrMode | 
                  AD7190_MODE_SEL((pwrMode * (AD7190_MODE_IDLE)) |
                                  (!pwrMode * (AD7190_MODE_PWRDN)));
     AD7190_SetRegisterValue(AD7190_REG_MODE, newPwrMode, 3, 1, 1);
}
void AD7190_SetLeds(unsigned char mode)
{
    st = 0;
    _CS_L
            
    switch (mode)
    {
        case 1:
    AD7190_SetRegisterValue(AD7190_REG_GPOCON, AD7190_GPOCON_GP10EN |
                                                AD7190_GPOCON_GP32EN |
                                                AD7190_GPOCON_P1DAT, 1, 1, 1); 
            break;
        case 2:
    AD7190_SetRegisterValue(AD7190_REG_GPOCON, AD7190_GPOCON_GP10EN |
                                                AD7190_GPOCON_GP32EN |
                                                AD7190_GPOCON_P0DAT, 1, 1, 1); 
            break;
        default:
    AD7190_SetRegisterValue(AD7190_REG_GPOCON, AD7190_GPOCON_GP10EN |
                                                AD7190_GPOCON_GP32EN |
                                                AD7190_GPOCON_P2DAT, 1, 1, 1); 
            break;
    }
    _CS_H
}

///***************************************************************************//**
// * @brief Waits for RDY pin to go low.
// *
// * @return none.
//*******************************************************************************/
void AD7190_WaitRdyGoLow(void)
{
    unsigned long timeOutCnt = 0xFFFFF;
    
    while(AD7190_RDY_STATE && timeOutCnt--);
}

/***************************************************************************//**
 * @brief Selects the channel to be enabled.
 *
 * @param channel - Selects a channel.
 *  
 * @return none.
*******************************************************************************/
void AD7190_ChannelSelect(unsigned short channel)
{
    st = 0;
    unsigned long oldRegValue = 0x0;
    unsigned long newRegValue = 0x0;   
     
    oldRegValue = AD7190_GetRegisterValue(AD7190_REG_CONF, 3, 1, 1);
    oldRegValue &= ~(AD7190_CONF_CHAN(0xFF));
    newRegValue = oldRegValue | AD7190_CONF_CHAN(1 << channel);   
    AD7190_SetRegisterValue(AD7190_REG_CONF, newRegValue, 3, 1, 1);
}

/***************************************************************************//**
 * @brief Performs the given calibration to the specified channel.
 *
 * @param mode - Calibration type.
 * @param channel - Channel to be calibrated.
 *
 * @return none.
*******************************************************************************/
void AD7190_Calibrate(unsigned char mode, unsigned char channel)
{
    unsigned long oldRegValue = 0x0;
    unsigned long newRegValue = 0x0;
    
    st = 0;
    AD7190_ChannelSelect(channel);
    oldRegValue = AD7190_GetRegisterValue(AD7190_REG_MODE, 3, 1, 1);
    oldRegValue &= ~AD7190_MODE_SEL(0x7);
    newRegValue = oldRegValue | AD7190_MODE_SEL(mode);
    _CS_L
    AD7190_SetRegisterValue(AD7190_REG_MODE, newRegValue, 3, 0, 1); // CS is not modified.
    AD7190_WaitRdyGoLow();
    HAL_Delay(10);
    _CS_H
}

/***************************************************************************//**
 * @brief Selects the polarity of the conversion and the ADC input range.
 *
 * @param polarity - Polarity select bit. 
                     Example: 0 - bipolar operation is selected.
                              1 - unipolar operation is selected.
* @param range - Gain select bits. These bits are written by the user to select 
                 the ADC input range.     
 *
 * @return none.
*******************************************************************************/
void AD7190_RangeSetup(unsigned char polarity, unsigned char range)
{
    st = 0;
    unsigned long oldRegValue = 0x0;
    unsigned long newRegValue = 0x0;
    
    oldRegValue = AD7190_GetRegisterValue(AD7190_REG_CONF,3, 1, 1);
    oldRegValue &= ~(AD7190_CONF_UNIPOLAR |
                     AD7190_CONF_GAIN(0x7));
    newRegValue = oldRegValue | 
                  (polarity * AD7190_CONF_UNIPOLAR) |
                  AD7190_CONF_GAIN(range); 
    AD7190_SetRegisterValue(AD7190_REG_CONF, newRegValue, 3, 1, 1);
}

/***************************************************************************//**
 * @brief Returns the result of a single conversion.
 *
 * @return regData - Result of a single analog-to-digital conversion.
*******************************************************************************/
unsigned long AD7190_SingleConversion(void)
{
    unsigned long command = 0x0;
    unsigned long regData = 0x0;
    unsigned long regRate = 0x0;
    unsigned long regPower = 0x0;
    
    st = 0;
    regRate = ReadMem(REG_ADC_REG1);
    if (regRate > 0x000003FF)
        regRate = 0x000003FF;
    regPower = ReadMem(REG_ADC_REG2);
    switch (regPower)
    {
        case 1:
            regPower = 0;
            break;
        case 8:
            regPower = 3;
            break;
        case 16:
            regPower = 4;
            break;
        case 32:
            regPower = 5;
            break;
        case 64:
            regPower = 6;
            break;
        case 128:
            regPower = 7;
            break;
        default:
            regPower = 0;
            break;
    }
    
    _CS_L
    AD7190_RangeSetup(1, regPower);
    AD7190_SetRegisterValue(AD7190_REG_MODE, command, 3, 1, 1); 
    AD7190_WaitRdyGoLow();
    HAL_Delay(1);
    regData = AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 1);
    _CS_H
    
    return regData;
}

/***************************************************************************//**
 * @brief Returns the average of several conversion results.
 *
 * @return samplesAverage - The average of the conversion results.
*******************************************************************************/
unsigned long AD7190_ContinuousReadAvg(unsigned char sampleNumber)
{
    st = 0;
    unsigned long samplesAverage = 0x0;
    unsigned char count = 0x0;
    unsigned long command = 0x0;
    
    command = AD7190_MODE_SEL(AD7190_MODE_CONT) | 
              AD7190_MODE_CLKSRC(AD7190_CLK_INT) |
              AD7190_MODE_RATE(0x060);
    _CS_L
    AD7190_SetRegisterValue(AD7190_REG_MODE, command, 3, 1, 1); // CS is not modified.
    for(count = 0;count < sampleNumber;count ++)
    {
        AD7190_WaitRdyGoLow();
        HAL_Delay(10);
        samplesAverage += AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 1); // CS is not modified.
    }
    _CS_H
    samplesAverage = samplesAverage / sampleNumber;
    
    return samplesAverage ;
}
/***************************************************************************//**
 * @brief Returns the average of several conversion results.
 *
 * @return samplesAverage - The average of the conversion results.
*******************************************************************************/
void AD7190_ContinuousReadStart()
{
    unsigned long samplesAverage = 0x0;
    unsigned long command = 0x0;
    
    _CS_H
    HAL_Delay(10);
    st = 1;
    command = AD7190_MODE_SEL(AD7190_MODE_CONT) | 
              AD7190_MODE_CLKSRC(AD7190_CLK_INT) |
              AD7190_MODE_RATE(0x060);
    _CS_L
    AD7190_SetRegisterValue(AD7190_REG_MODE, command, 3, 1, 1); 
    HAL_Delay(1);
    
    return samplesAverage ;
}
/***************************************************************************//**
 * @brief Returns the average of several conversion results.
 *
 * @return samplesAverage - The average of the conversion results.
*******************************************************************************/
unsigned long AD7190_ContinuousRead()
{
    if (st == 0)
        AD7190_ContinuousReadStart();
        
    char buffer[100];
    int chn;   
    unsigned long samplesAverage = 0x0;
    samplesAverage = AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 1); 
//    _CS_H
//    chn=sprintf(buffer," d%d",samplesAverage);
//    HAL_UART_Transmit(&huart1, buffer, chn, 10000);   
    
    return samplesAverage ;
}
/***************************************************************************//**
 * @brief Returns the average of several conversion results.
 *
 * @return samplesAverage - The average of the conversion results.
*******************************************************************************/
void AD7190_ContinuousReadStop()
{
    st = 0;
    _CS_H
    
    return ;
}

/***************************************************************************//**
 * @brief Read data from temperature sensor and converts it to Celsius degrees.
 *
 * @return temperature - Celsius degrees.
*******************************************************************************/
unsigned long AD7190_TemperatureRead(void)
{
    unsigned char temperature = 0x0;
    unsigned long dataReg = 0x0;
    
    st = 0;
    AD7190_RangeSetup(0, AD7190_CONF_GAIN_1);
    AD7190_ChannelSelect(AD7190_CH_TEMP_SENSOR);
    dataReg = AD7190_SingleConversion();
    dataReg -= 0x800000;
    dataReg /= 2815;   // Kelvin Temperature
    dataReg -= 273;    //Celsius Temperature
    temperature = (unsigned long) dataReg;
    
    return temperature;
}
unsigned long AD7190_1_ch(void)
{
    unsigned char data = 0x0;
    unsigned long dataReg = 0x0;
    
    st = 0;
    AD7190_RangeSetup(1, AD7190_CONF_GAIN_1);
    AD7190_ChannelSelect(AD7190_CH_AIN1P_AINCOM);
    dataReg = AD7190_SingleConversion();
    
    return dataReg;
}
unsigned long AD7190_2_ch(void)
{
    unsigned char data = 0x0;
    unsigned long dataReg = 0x0;
    
    st = 0;
    AD7190_RangeSetup(1, AD7190_CONF_GAIN_1);
    AD7190_ChannelSelect(AD7190_CH_AIN2P_AINCOM);
    dataReg = AD7190_SingleConversion();
    
    return dataReg;
}
unsigned long AD7190_3_ch(void)
{
    unsigned char data = 0x0;
    unsigned long dataReg = 0x0;
    
    st = 0;
    AD7190_RangeSetup(1, AD7190_CONF_GAIN_1);
    AD7190_ChannelSelect(AD7190_CH_AIN3P_AINCOM);
    dataReg = AD7190_SingleConversion();
    
    return dataReg;
}
unsigned long AD7190_4_ch(void)
{
    unsigned char data = 0x0;
    unsigned long dataReg = 0x0;
    
    st = 0;
    AD7190_RangeSetup(1, AD7190_CONF_GAIN_1);
    AD7190_ChannelSelect(AD7190_CH_AIN4P_AINCOM);
    dataReg = AD7190_SingleConversion();
    
    return dataReg;
}


///////////////////////////////////////////////////////////////////////////////////////////////
unsigned int stateM = 0;
int getState(void)
{
    return stateM;
}
uint8_t buffer2[5] = {0,0,0,0,0};
int initiateDMATestCycle(void)
{
    stateM = 10;
    HAL_SPI_TransmitReceive(&hspi1, buffer2, buffer2, 5, 10000); 
    HAL_UART_Transmit(&huart1, "|", 1, 10000);
}
int DMATestCycle(void)
{
    if (stateM == 10)
        HAL_SPI_TransmitReceive(&hspi1, buffer2, buffer2, 5, 10000);  
    HAL_UART_Transmit(&huart1, "*", 1, 10000);      
}
int initiateConversionCycle(void)
{
//    HAL_SPI_Transmit_DMA(&hspi1, "-----", 5);
    _CS_H
    HAL_Delay(1);
    stateM = 0;
    if (stateM != 0)
        return -1;
    _CS_L
    stateM = 1;
//    HAL_UART_Transmit(&huart1, "1", 1, 10000);
    unsigned long command = 0x0;
    command = AD7190_MODE_SEL(AD7190_MODE_CONT) | 
              AD7190_MODE_CLKSRC(AD7190_CLK_INT) |
              AD7190_MODE_DAT_STA |
              AD7190_MODE_RATE(0x3FF);
    AD7190_SetRegisterValue(AD7190_REG_MODE, command, 3, 1, 0); // non blocking
    command = AD7190_CONF_CHAN(AD7190_CH_TEMP_SENSOR |
                                AD7190_CH_AIN1P_AINCOM |
                                AD7190_CH_AIN2P_AINCOM |
                                AD7190_CH_AIN3P_AINCOM |
                                AD7190_CH_AIN4P_AINCOM) |
              AD7190_CONF_GAIN(AD7190_CONF_GAIN_1);
    AD7190_SetRegisterValue(AD7190_REG_CONF, command, 3, 1, 0); // non blocking
    stateM = 2;
//    HAL_UART_Transmit(&huart1, "2", 1, 10000);
    return 0;
}
int breakConversionCycle(void)
{
    _CS_H
    stateM = 0;
//    HAL_UART_Transmit(&huart1, "0", 1, 10000);
}
char state_history = 0;
char state_history_buf[32];
int observerConversionCycle(void)
{
    state_history_buf[state_history%32] = stateM;
    unsigned long i = 0x0;
    for(i = 1; i < 32; i++) 
    {
        if (state_history_buf[i-1] != state_history_buf[i])
        {
            HAL_UART_Transmit(&huart1, "Reinit", 6, 10000);
            state_history_buf[state_history%32] = !state_history_buf[state_history%32];
            return 1;
        }
    }
    state_history++;
    return 0;
}

int modeSendedInConversionCycle(void)
{
    if (stateM != 2)
        return -1;
    AD7190_WaitRdyGoLow();
    HAL_Delay(1);
    stateM = 3;
    HAL_UART_Transmit(&huart1, "|", 1, 10000);
    AD7190_GetRegisterValue(AD7190_REG_DATA, 3, 1, 0); 
    stateM = 4;
//    HAL_UART_Transmit(&huart1, "4", 1, 10000);
}
int dataReceivedInConversionCycle(void)
{
    if (stateM != 4)
        return -1;
//    if ((samplesAverage & 0x02000000) > 0)
//        WriteMem(REG_ADC_CH1,samplesAverage & 0x00FFFFFF);
//    if ((samplesAverage & 0x04000000) > 0)
//        WriteMem(REG_ADC_CH2,samplesAverage & 0x00FFFFFF);
//    if ((samplesAverage & 0x05000000) > 0)
//        WriteMem(REG_ADC_CH3,samplesAverage & 0x00FFFFFF);
//    if ((samplesAverage & 0x06000000) > 0)
//        WriteMem(REG_ADC_CH4,samplesAverage & 0x00FFFFFF);
//    if ((samplesAverage & 0x07000000) > 0)
//        WriteMem(REG_ADC_CH5,samplesAverage & 0x00FFFFFF);
    unsigned long buffer = 0x0;
    unsigned long i = 0x0;
    for(i = 1; i < 4; i++) 
    {
        buffer = (buffer << 8) + non_block_registerWord[i];
    }
//    buffer;
    AD7190_WaitRdyGoLow();
    HAL_Delay(1);
    stateM = 3;
    HAL_UART_Transmit(&huart1, "*", 1, 10000);
    AD7190_GetRegisterValue(AD7190_REG_DATA, 4, 1, 0); 
    stateM = 4;
//    HAL_UART_Transmit(&huart1, "4", 1, 10000);
}



/************************************* END LINE ************************************************/