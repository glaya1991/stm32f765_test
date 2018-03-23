#include "stm32f7xx_hal.h"
#include "ILI9341_dma.h"
#include "ILI9341_delay.h"
#include "spi.h"
#include "usart.h"

//DMA_InitTypeDef dmaStructure;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;
DMA_TypeDef dma_spi1;
uint8_t flag_spi1_dma;

//#define CMD_CMSIS 

#define SPI1_DR_8bit          (*(__IO uint8_t *)((uint32_t)&(SPI1->DR))) 
#define SPI4_DR_8bit          (*(__IO uint8_t *)((uint32_t)&(SPI4->DR)))

#define DMA_BUF_SIZE 2048
uint16_t dmaBufIndex = 0;
uint16_t dmaBuffer[DMA_BUF_SIZE];

void dmaInit(void) {
    
    __HAL_RCC_DMA2_CLK_ENABLE();

    // RX
    /* DMA2_Stream0_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
    //HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
    
    // TX
    /* DMA2_Stream1_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
    //HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

    //SPI_I2S_DMACmd(SPI_MASTER, SPI_I2S_DMAReq_Tx, ENABLE);
    //SPI_I2S_DMACmd(SPI_MASTER, SPI_I2S_DMAReq_Rx, ENABLE);
}

//<editor-fold desc="Dma init options and start">

inline static void dmaReceive8(uint32_t *SrcAddress, uint32_t *DstAddress, uint32_t n) {
   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
  //  dmaStructure.DMA_BufferSize     = n;

//    dmaStructure.Mode            	= DMA_NORMAL;
//    dmaStructure.MemInc          	= DMA_MINC_ENABLE;
//    dmaStructure.Direction                = DMA_PERIPH_TO_MEMORY;
//    dmaStructure.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
//    dmaStructure.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//
//    dmaStartRx(addr, data, n);
}


// from spi.c //

/* SPI1_TX Init */
/*
    hdma_spi1_tx.Instance = DMA2_Stream3;
    hdma_spi1_tx.Init.Channel = DMA_CHANNEL_3;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      _Error_Handler(__FILE__, __LINE__);
    }
    */
    
//inline static void 
inline static void dmaSend8(uint8_t *data, uint32_t n) {    
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;   
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority= DMA_PRIORITY_MEDIUM;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      _Error_Handler(__FILE__, __LINE__);
    }   
    
    flag_spi1_dma=0;
    HAL_SPI_Transmit_DMA(&hspi1, data, n);
    //hdma_spi1_tx.Instance->M0AR=(uint32_t)data;
    //hdma_spi1_tx.Instance->PAR=(uint32_t)(&hspi1.Instance->DR);
    //hdma_spi1_tx.Instance->CR|=1;
    //hdma_spi1_tx.Instance->NDTR=n;
    while(flag_spi1_dma!=1);
    
    
//    DMA_StructInit(&dmaStructure);
//    //dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
//    //dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
//    //dmaStructure.DMA_BufferSize     = n;
//    dmaStructure.Mode            		= DMA_NORMAL;
//    dmaStructure.MemInc          		= DMA_MINC_ENABLE;
//    dmaStructure.Direction              = DMA_MEMORY_TO_PERIPH;
//    dmaStructure.MemDataAlignment    	= DMA_MDATAALIGN_BYTE;
//    dmaStructure.PeriphDataAlignment 	= DMA_PDATAALIGN_BYTE;
//    dmaStructure.Priority= DMA_PRIORITY_MEDIUM;    
//    dmaStartTx(SrcAddress, DstAddress, n);
}

//static
inline static void dmaSendCircular16(uint8_t *data, uint32_t n) {
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;   
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_CIRCULAR;
    hdma_spi1_tx.Init.FIFOMode=DMA_FIFOMODE_DISABLE;
    
    hdma_spi1_tx.Init.Priority= DMA_PRIORITY_MEDIUM;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK){
      _Error_Handler(__FILE__, __LINE__);
    }
    
    flag_spi1_dma=0;
    HAL_SPI_Transmit_DMA(&hspi1, data, n);
//    hdma_spi1_tx.Instance->M0AR=(uint32_t)data;
//    hdma_spi1_tx.Instance->PAR=(uint32_t)(&hspi1.Instance->DR);
//    hdma_spi1_tx.Instance->NDTR=n;
//    hdma_spi1_tx.Instance->CR|=1;
    while(flag_spi1_dma!=1);

    
      
      
//    DMA_StructInit(&dmaStructure);
//    //dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
//    dmaStructure.Priority           = DMA_PRIORITY_MEDIUM;
//   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
//   // dmaStructure.DMA_BufferSize     = n;
//    dmaStructure.Mode               		= DMA_CIRCULAR;
//    dmaStructure.MemInc          			= DMA_MINC_DISABLE;
//    dmaStructure.Direction             		= DMA_MEMORY_TO_PERIPH;
//    dmaStructure.MemDataAlignment     		= DMA_MDATAALIGN_HALFWORD;
//    dmaStructure.PeriphDataAlignment 		= DMA_PDATAALIGN_HALFWORD;
//    dmaStartTx(SrcAddress, DstAddress, n);
}

inline static void dmaSend16(uint8_t *data, uint32_t n) {
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;   
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.FIFOMode=DMA_FIFOMODE_DISABLE;
    hdma_spi1_tx.Init.Priority= DMA_PRIORITY_MEDIUM;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      _Error_Handler(__FILE__, __LINE__);
    }
    
    flag_spi1_dma=0;
    HAL_SPI_Transmit_DMA(&hspi1, data, n);
//    dma_spi1.LISR=0xFFFF; 
//    hdma_spi1_tx.Instance->M0AR=(uint32_t)data;
//    hdma_spi1_tx.Instance->PAR=(uint32_t)(&hspi1.Instance->DR);
//    hdma_spi1_tx.Instance->NDTR=n;
//    hdma_spi1_tx.Instance->CR|=1|(1<<4);
    while(flag_spi1_dma!=1);

    
    
    
//    DMA_StructInit(&dmaStructure);
//   // dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
//    dmaStructure.Priority           = DMA_PRIORITY_MEDIUM;
//   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
//   // dmaStructure.DMA_BufferSize     = n;
//    dmaStructure.Mode            			= DMA_NORMAL;
//    dmaStructure.MemInc          			= DMA_MINC_ENABLE;
//    dmaStructure.Direction              	= DMA_MEMORY_TO_PERIPH;
//    dmaStructure.MemDataAlignment    		= DMA_MDATAALIGN_HALFWORD;
//    dmaStructure.PeriphDataAlignment 		= DMA_PDATAALIGN_HALFWORD;
//    dmaStartTx(SrcAddress, DstAddress, n);
}

//</editor-fold>

//<editor-fold desc="DMA send receive functions">

inline void dmaSendCmd(uint8_t cmd) {
    TFT_CS_RESET;
    TFT_DC_RESET;

#ifdef CMD_CMSIS
        SPI1_DR_8bit=cmd;
        while((SPI_MASTER->SR & (1<<1))==0){};
        //HAL_SPI_Transmit(&hspi1, &cmd, 1, 1);
#else
        dmaSend8(&cmd, 1);
        //dmaWait(flag_spi1_dma);
#endif

    //HAL_UART_Transmit(&huart1, &cmd, 1, 100);
    TFT_CS_SET;
}

inline void dmaSendCmdCont(uint8_t cmd) {
    TFT_DC_RESET;
    
#ifdef CMD_CMSIS
        SPI1_DR_8bit=cmd;
        while((SPI_MASTER->SR & (1<<1))==0){};
#else
        dmaSend8(&cmd, 1);
        //dmaWait(flag_spi1_dma);  
#endif

    //HAL_UART_Transmit(&huart1, &cmd, 1, 100);
}

inline void dmaReceiveDataCont8(uint8_t *data) {
    uint8_t dummy = 0xFF;
    HAL_SPI_Transmit(&hspi1, &dummy, 1, 1);
//    dmaSend8(&dummy, 1);
//    dmaReceive8(data, 1);
//    dmaWait();
}

inline void dmaSendData8(uint8_t *data, uint32_t n) {
    TFT_CS_RESET;
    TFT_DC_SET;
    /*
    while(n!=0){
        SPI1_DR_8bit=*(data++);
        while((SPI_MASTER->SR & (1<<1))==0){};
        n--;
    }
     */
   HAL_SPI_Transmit(&hspi1, data, n, 1);
//    HAL_UART_Transmit(&huart1, data, n, 100);
//    dmaSend8(data, n);
//    dmaWait();
    TFT_CS_SET;
}

inline void dmaSendDataCont8(uint8_t *data, uint32_t n) {
    TFT_DC_SET;
    
#ifdef CMD_CMSIS
    while(n!=1){
        SPI1_DR_8bit=*(data++);
        while((SPI_MASTER->SR & (1<<1))==0){};
        n--;
    }   
    SPI1_DR_8bit=*(data);
    while((SPI_MASTER->SR & (1<<1))==0){};
#else
    flag_spi1_dma=0;
    dmaSend8(data, n);
    //while(flag_spi1_dma!=1){};
    //dmaWait(flag_spi1_dma);   
#endif

//    HAL_UART_Transmit(&huart1, data, n, 100);
}

inline void dmaSendData16(uint16_t *data, uint32_t n) {    
    TFT_CS_RESET;
    TFT_DC_SET;
#ifdef CMD_CMSIS
    while(n!=0){
        SPI_MASTER->DR=*(data++);
        while((SPI_MASTER->SR & (1<<7))!=0){};
        n--;
    }
#else
    flag_spi1_dma=0;
    dmaSend16(data, n);
    //while(flag_spi1_dma!=1){};
    //dmaWait(flag_spi1_dma);
#endif
    TFT_CS_SET;
}

inline void dmaSendDataCont16(uint16_t *data, uint32_t n) {
    TFT_DC_SET; 
    
#ifdef CMD_CMSIS
    while(n!=1){             
        SPI_MASTER->DR=*(data++);
        while((SPI_MASTER->SR & (1<<7))==1){};
        //HAL_UART_Transmit(&huart1, uart_tx, 2, 100);
        n--;
    }
    SPI_MASTER->DR=*(data);
    while((SPI_MASTER->SR & (1<<7))==1){};
#else
    flag_spi1_dma=0;
    dmaSend16(data, n);
    //while(flag_spi1_dma!=1){};
    //dmaWait(flag_spi1_dma);
#endif
}

inline void dmaSendDataBuf16() {
    if(dmaBufIndex == 0) return;
    TFT_DC_SET;
    HAL_SPI_Transmit(&hspi1, dmaBuffer, dmaBufIndex, 100);
//    dmaSend16(dmaBuffer, dmaBufIndex);
    dmaBufIndex = 0;
//    dmaWait();
}

inline void dmaSendDataContBuf16(uint16_t *data, uint32_t n) {
    while (n--) {
        dmaBuffer[dmaBufIndex] = *data++;
        if (dmaBufIndex == DMA_BUF_SIZE - 1) {
           dmaSendDataBuf16();
        }
        dmaBufIndex++;
    }
}


 void dmaSendDataCircular16(uint16_t *data, uint32_t n) {
    TFT_DC_SET;  
#ifdef CMD_CMSIS
    while(n!=0){ 
        SPI_MASTER->DR=*(data);
        while((SPI_MASTER->SR & (1<<7))!=0){};
        n--;
    }   
#else
    uint32_t i,len=n<<1;
    uint8_t buf[len];
    for(i=0;i<len;i=i+2){
        buf[i]=*(data)>>8;
        buf[i+1]=*(data);
    }
   dmaSend16(buf,len);
  // dmaSendCircular16(buf,len);
    //while(flag_spi1_dma!=1){};
    //dmaWait(flag_spi1_dma);
#endif
}

//</editor-fold>

inline void dmaFill16(uint16_t color, uint32_t n) {      
    TFT_CS_RESET; 
    TFT_DC_SET;
    while (n != 0) {
        uint16_t ts = (uint16_t) (n > UINT16_MAX ? UINT16_MAX : n);
        dmaSendDataCircular16(&color, ts);
        n -= ts;
    }
    TFT_CS_SET;
}

//<editor-fold desc="IRQ handlers">

void DMA1_Channel2_IRQHandler(void) {
//    if (DMA_GetITStatus(DMA1_IT_TC2) == SET) {
//        DMA_Cmd(DMA1_Channel2, DISABLE);
//        DMA_ClearITPendingBit(DMA1_IT_TC2);
//    }
}

void DMA1_Channel3_IRQHandler(void) {
//    if (DMA_GetITStatus(DMA1_IT_TC3) == SET) {
//        DMA_Cmd(DMA1_Channel3, DISABLE);
//        DMA_ClearITPendingBit(DMA1_IT_TC3);
//    }
}

//</editor-fold>
