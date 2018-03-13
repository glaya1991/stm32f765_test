#include "dma.h"

DMA_InitTypeDef dmaStructure;

#define DMA_BUF_SIZE 2048
uint16_t dmaBufIndex = 0;
uint16_t dmaBuffer[DMA_BUF_SIZE];

void dmaInit(void) {
	  __HAL_RCC_DMA2_CLK_ENABLE();

    // RX
    /* DMA2_Stream0_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
    // TX
    /* DMA2_Stream1_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

    //SPI_I2S_DMACmd(SPI_MASTER, SPI_I2S_DMAReq_Tx, ENABLE);
    //SPI_I2S_DMACmd(SPI_MASTER, SPI_I2S_DMAReq_Rx, ENABLE);
}

//<editor-fold desc="Dma init options and start">

inline static void dmaReceive8(uint32_t *SrcAddress, uint32_t *DstAddress, uint32_t n) {
   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
  //  dmaStructure.DMA_BufferSize     = n;

    dmaStructure.Mode            	= DMA_NORMAL;
    dmaStructure.MemInc          	= DMA_MINC_ENABLE;
    dmaStructure.Direction                = DMA_PERIPH_TO_MEMORY;
    dmaStructure.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
    dmaStructure.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

    dmaStartRx(addr, data, n);
}

inline static void dmaSend8(uint32_t *SrcAddress, uint32_t *DstAddress, uint32_t n) {
    DMA_StructInit(&dmaStructure);
    //dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
    dmaStructure.Priority           = DMA_PRIORITY_MEDIUM;

    //dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
    //dmaStructure.DMA_BufferSize     = n;

    dmaStructure.Mode            		= DMA_NORMAL;
    dmaStructure.MemInc          		= DMA_MINC_ENABLE;
    dmaStructure.Direction              = DMA_MEMORY_TO_PERIPH;
    dmaStructure.MemDataAlignment    	= DMA_MDATAALIGN_BYTE;
    dmaStructure.PeriphDataAlignment 	= DMA_PDATAALIGN_BYTE;

    dmaStartTx(SrcAddress, DstAddress, n);
}

inline static void dmaSendCircular16(uint32_t *SrcAddress, uint32_t *DstAddress, uint32_t n) {
    DMA_StructInit(&dmaStructure);
    //dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
    dmaStructure.Priority           = DMA_PRIORITY_MEDIUM;

   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
   // dmaStructure.DMA_BufferSize     = n;

    dmaStructure.Mode               		= DMA_CIRCULAR;
    dmaStructure.MemInc          			= DMA_MINC_DISABLE;
    dmaStructure.Direction             		= DMA_MEMORY_TO_PERIPH;
    dmaStructure.MemDataAlignment     		= DMA_MDATAALIGN_HALFWORD;
    dmaStructure.PeriphDataAlignment 		= DMA_PDATAALIGN_HALFWORD;

    dmaStartTx(SrcAddress, DstAddress, n);
}

inline static void dmaSend16(uint32_t *SrcAddress, uint32_t *DstAddress, uint32_t n) {
    DMA_StructInit(&dmaStructure);
   // dmaStructure.DMA_PeripheralBaseAddr = (uint32_t) &(SPI_MASTER->DR);
    dmaStructure.Priority           = DMA_PRIORITY_MEDIUM;

   // dmaStructure.DMA_MemoryBaseAddr = (uint32_t) data;
   // dmaStructure.DMA_BufferSize     = n;

    dmaStructure.Mode            			= DMA_NORMAL;
    dmaStructure.MemInc          			= DMA_MINC_ENABLE;
    dmaStructure.Direction              	= DMA_MEMORY_TO_PERIPH;
    dmaStructure.MemDataAlignment    		= DMA_MDATAALIGN_HALFWORD;
    dmaStructure.PeriphDataAlignment 		= DMA_PDATAALIGN_HALFWORD;

    dmaStartTx(SrcAddress, DstAddress, n);
}

//</editor-fold>

//<editor-fold desc="DMA send receive functions">

inline void dmaSendCmd(uint8_t cmd) {
    TFT_CS_RESET;
    TFT_DC_RESET;
    dmaSend8(&cmd, 1);
    dmaWait();
    TFT_CS_SET;
}

inline void dmaSendCmdCont(uint8_t cmd) {
    TFT_DC_RESET;
    dmaSend8(&cmd, 1);
    dmaWait();
}

inline void dmaReceiveDataCont8(uint8_t *data) {
    uint8_t dummy = 0xFF;
    dmaSend8(&dummy, 1);
    dmaReceive8(data, 1);
    dmaWait();
}

inline void dmaSendData8(uint8_t *data, uint32_t n) {
    TFT_CS_RESET;
    TFT_DC_SET;
    dmaSend8(data, n);
    dmaWait();
    TFT_CS_SET;
}

inline void dmaSendDataCont8(uint8_t *data, uint32_t n) {
    TFT_DC_SET;
    dmaSend8(data, n);
    dmaWait();
}

inline void dmaSendData16(uint16_t *data, uint32_t n) {
    TFT_CS_RESET;
    TFT_DC_SET;
    dmaSend16(data, n);
    dmaWait();
    TFT_CS_SET;
}

inline void dmaSendDataCont16(uint16_t *data, uint32_t n) {
    TFT_DC_SET;
    dmaSend16(data, n);
    dmaWait();
}

inline void dmaSendDataBuf16() {
    if(dmaBufIndex == 0) return;
    TFT_DC_SET;
    dmaSend16(dmaBuffer, dmaBufIndex);
    dmaBufIndex = 0;
    dmaWait();
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


inline void dmaSendDataCircular16(uint16_t *data, uint32_t n) {
    TFT_DC_SET;
    dmaSendCircular16(data, n);
    dmaWait();
}

//</editor-fold>

inline void dmaFill16(uint16_t color, uint32_t n) {
    TFT_CS_RESET;
    dmaSendCmdCont(LCD_GRAM);
    while (n != 0) {
        uint16_t ts = (uint16_t) (n > UINT16_MAX ? UINT16_MAX : n);
        dmaSendDataCircular16(&color, ts);
        n -= ts;
    }
    TFT_CS_SET;
}

//<editor-fold desc="IRQ handlers">

void DMA1_Channel2_IRQHandler(void) {
    if (DMA_GetITStatus(DMA1_IT_TC2) == SET) {
        DMA_Cmd(DMA1_Channel2, DISABLE);
        DMA_ClearITPendingBit(DMA1_IT_TC2);
    }
}

void DMA1_Channel3_IRQHandler(void) {
    if (DMA_GetITStatus(DMA1_IT_TC3) == SET) {
        DMA_Cmd(DMA1_Channel3, DISABLE);
        DMA_ClearITPendingBit(DMA1_IT_TC3);
    }
}

//</editor-fold>
