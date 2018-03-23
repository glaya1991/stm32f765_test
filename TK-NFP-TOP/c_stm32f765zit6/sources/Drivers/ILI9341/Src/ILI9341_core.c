#include "stm32f7xx_hal.h"
#include "ILI9341_core.h"
//#include "ILI9341_core.h"
#include "stm32f7xx_hal_gpio.h"
#include "spi.h"

static uint16_t screen_width  = LCD_PIXEL_WIDTH,
    screen_height = LCD_PIXEL_HEIGHT;

//<editor-fold desc="Init commands">

static const uint8_t init_commands[] = {
        // Power control A
        6, LCD_POWERA, 0x39, 0x2C, 0x00, 0x34, 0x02,
        // Power control B
        4, LCD_POWERB, 0x00, 0xC1, 0x30,
        // Driver timing control A
        4, LCD_DTCA, 0x85, 0x00, 0x78,
        // Driver timing control B
        3, LCD_DTCB, 0x00, 0x00,
        // Power on sequence control
        5, LCD_POWER_SEQ, 0x64, 0x03, 0x12, 0x81,
        // Pump ratio control
        2, LCD_PRC, 0x20,
        // Power control 1
        2, LCD_POWER1, 0x23,
        // Power control 2
        2, LCD_POWER2, 0x10,
        // VCOM control 1
        3, LCD_VCOM1, 0x3E, 0x28,
        // VCOM cotnrol 2
        2, LCD_VCOM2, 0x86,
        // Memory access control
        2, LCD_MAC, 0x48,
        // Pixel format set
        2, LCD_PIXEL_FORMAT, 0x55,
        // Frame rate control
        3, LCD_FRMCTR1, 0x00, 0x18,
        // Display function control
        4, LCD_DFC, 0x08, 0x82, 0x27,
        // 3Gamma function disable
        2, LCD_3GAMMA_EN, 0x00,
        // Gamma curve selected
        2, LCD_GAMMA, 0x01,
        // Set positive gamma
        16, LCD_PGAMMA, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
        16, LCD_NGAMMA, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
        0
};

//</editor-fold>

//<editor-fold desc="LCD initialization functions">

 void LCD_pinsInit() {      //static
    //SPI_InitTypeDef  spiStructure;
    //GPIO_InitTypeDef gpioStructure;
    
    
/*
    HAL_RCC_PCLK2Config(RCC_HCLK_Div2);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_AFIOEN, ENABLE);
    RCC_APB2PeriphClockCmd(SPI_MASTER_GPIO_CLK | SPI_MASTER_CLK, ENABLE);

    // GPIO speed by default
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;

    // GPIO for CS/DC/LED/RESET
    gpioStructure.GPIO_Pin  = TFT_CS_PIN | TFT_DC_PIN | TFT_RESET_PIN | TFT_LED_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &gpioStructure);

    // GPIO for SPI
    gpioStructure.GPIO_Pin  = SPI_MASTER_PIN_SCK | SPI_MASTER_PIN_MOSI;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(SPI_MASTER_GPIO, &gpioStructure);

    // GPIO for SPI
    gpioStructure.GPIO_Pin  = SPI_MASTER_PIN_MISO;
    gpioStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(SPI_MASTER_GPIO, &gpioStructure);

    SPI_StructInit(&spiStructure);
    spiStructure.SPI_Mode              = SPI_Mode_Master;
    spiStructure.SPI_NSS               = SPI_NSS_Soft;
    spiStructure.SPI_CPOL              = SPI_CPOL_High;
    spiStructure.SPI_CPHA              = SPI_CPHA_2Edge;
    spiStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    SPI_Init(SPI_MASTER, &spiStructure);

    SPI_Cmd(SPI_MASTER, ENABLE);
    */
}

void LCD_reset() {
    TFT_RST_RESET;
    HAL_Delay(10);
    //delay_ms(10);
    
    TFT_RST_SET;
    HAL_Delay(50);
    //delay_ms(50);
}

void LCD_exitStandby() {
    dmaSendCmd(LCD_SLEEP_OUT);
    HAL_Delay(150);
    //delay_ms(150);
    
    //dmaSendCmd(0x01);
    //HAL_Delay(1000);
    
    dmaSendCmd(LCD_DISPLAY_ON);
}

void LCD_configure() {      //static 
    uint8_t count;
    uint8_t *address = (uint8_t *) init_commands;
    //LCD_setSpi8();   

    TFT_CS_RESET;
    while (1) {
        count = *(address++);
        if (count-- == 0) break;
        dmaSendCmdCont(*(address++));
        dmaSendDataCont8(address, count);
        address += count;
    }
    TFT_CS_SET;

    LCD_setOrientation(0);
}

/*Send data (char) to LCD*/
void ILI9341_SPI_Send(unsigned char SPI_Data)
{
    HAL_SPI_Transmit(&hspi1, &SPI_Data, 1, 1);
 //ILI9341_SPI_Send_Byte(SPI_Data);
}

/* Send command (char) to LCD */
void ILI9341_Write_Command(uint8_t Command)
{
uint8_t i;
//HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);
TFT_DC_RESET;
TFT_CS_RESET;
ILI9341_SPI_Send(Command);
//HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);
TFT_CS_SET;
//for(i=0;i<20;i++);
}

/* Send Data (char) to LCD */
void ILI9341_Write_Data(uint8_t Data)
{
uint8_t i;
//HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);
//HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);
TFT_DC_SET;
TFT_CS_RESET;
ILI9341_SPI_Send(Data);	
//HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);
TFT_CS_SET;
//for(i=0;i<10;i++);
}

void LCD_configure1() {
//SOFTWARE RESET
ILI9341_Write_Command(0x01);
HAL_Delay(1000);
	
//POWER CONTROL A

ILI9341_Write_Command(0xCB);
ILI9341_Write_Data(0x39);
ILI9341_Write_Data(0x2C);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0x34);
ILI9341_Write_Data(0x02);


//POWER CONTROL B

ILI9341_Write_Command(0xCF);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0xC1);
ILI9341_Write_Data(0x30);



//DRIVER TIMING CONTROL A
ILI9341_Write_Command(0xE8);
ILI9341_Write_Data(0x85);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0x78);

//DRIVER TIMING CONTROL B
ILI9341_Write_Command(0xEA);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0x00);

//POWER ON SEQUENCE CONTROL
ILI9341_Write_Command(0xED);
ILI9341_Write_Data(0x64);
ILI9341_Write_Data(0x03);
ILI9341_Write_Data(0x12);
ILI9341_Write_Data(0x81);

//PUMP RATIO CONTROL
ILI9341_Write_Command(0xF7);
ILI9341_Write_Data(0x20);

//POWER CONTROL,VRH[5:0]
ILI9341_Write_Command(0xC0);
ILI9341_Write_Data(0x23);

//POWER CONTROL,SAP[2:0];BT[3:0]
ILI9341_Write_Command(0xC1);
ILI9341_Write_Data(0x10);

//VCM CONTROL
ILI9341_Write_Command(0xC5);
ILI9341_Write_Data(0x3E);
ILI9341_Write_Data(0x28);

//VCM CONTROL 2
ILI9341_Write_Command(0xC7);
ILI9341_Write_Data(0x86);

//MEMORY ACCESS CONTROL
ILI9341_Write_Command(0x36);
ILI9341_Write_Data(0x48);

//PIXEL FORMAT	- 16 bit-format
ILI9341_Write_Command(0x3A);
ILI9341_Write_Data(0x55);

//FRAME RATIO CONTROL, STANDARD RGB COLOR
ILI9341_Write_Command(0xB1);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0x18);		//0x18 - 24 clock per line, 0x10 - 16 clock per line


//BRIGHTNESS
ILI9341_Write_Command(0x51);
ILI9341_Write_Data(0xFF);

ILI9341_Write_Command(0x51);
ILI9341_Write_Data(0xFF);


//DISPLAY FUNCTION CONTROL
ILI9341_Write_Command(0xB6);
ILI9341_Write_Data(0x08);
ILI9341_Write_Data(0x82);
ILI9341_Write_Data(0x27);

//3GAMMA FUNCTION DISABLE
ILI9341_Write_Command(0xF2);
ILI9341_Write_Data(0x00);

//GAMMA CURVE SELECTED
ILI9341_Write_Command(0x26);
ILI9341_Write_Data(0x01);

//POSITIVE GAMMA CORRECTION
ILI9341_Write_Command(0xE0);
ILI9341_Write_Data(0x0F);
ILI9341_Write_Data(0x31);
ILI9341_Write_Data(0x2B);
ILI9341_Write_Data(0x0C);
ILI9341_Write_Data(0x0E);
ILI9341_Write_Data(0x08);
ILI9341_Write_Data(0x4E);
ILI9341_Write_Data(0xF1);
ILI9341_Write_Data(0x37);
ILI9341_Write_Data(0x07);
ILI9341_Write_Data(0x10);
ILI9341_Write_Data(0x03);
ILI9341_Write_Data(0x0E);
ILI9341_Write_Data(0x09);
ILI9341_Write_Data(0x00);

//NEGATIVE GAMMA CORRECTION
ILI9341_Write_Command(0xE1);
ILI9341_Write_Data(0x00);
ILI9341_Write_Data(0x0E);
ILI9341_Write_Data(0x14);
ILI9341_Write_Data(0x03);
ILI9341_Write_Data(0x11);
ILI9341_Write_Data(0x07);
ILI9341_Write_Data(0x31);
ILI9341_Write_Data(0xC1);
ILI9341_Write_Data(0x48);
ILI9341_Write_Data(0x08);
ILI9341_Write_Data(0x0F);
ILI9341_Write_Data(0x0C);
ILI9341_Write_Data(0x31);
ILI9341_Write_Data(0x36);
ILI9341_Write_Data(0x0F);

//EXIT SLEEP
ILI9341_Write_Command(0x11);
HAL_Delay(120);

//TURN ON DISPLAY
ILI9341_Write_Command(0x29);

//STARTING ROTATION
//ILI9341_Set_Rotation(SCREEN_VERTICAL_1, RGB_order);
}

void LCD_fillScreen1(uint16_t Colour)
{
ILI9341_Write_Command(0x2A);    //X
ILI9341_Write_Data(0>>8);
ILI9341_Write_Data(0);
ILI9341_Write_Data(LCD_PIXEL_WIDTH>>8);
ILI9341_Write_Data(LCD_PIXEL_WIDTH&0xFF);

ILI9341_Write_Command(0x2B);    //Y
ILI9341_Write_Data(0>>8);
ILI9341_Write_Data(0);
ILI9341_Write_Data(LCD_PIXEL_HEIGHT>>8);
ILI9341_Write_Data(LCD_PIXEL_HEIGHT&0xFF);

ILI9341_Write_Command(0x2C);

uint32_t j;
uint32_t Size = LCD_PIXEL_WIDTH*LCD_PIXEL_HEIGHT;
uint32_t Buffer_Size;

Buffer_Size=400;

unsigned char chifted = Colour>>8;
unsigned char burst_buffer[Buffer_Size];
for(j = 0; j < Buffer_Size; j+=2){
		burst_buffer[j] = chifted;
		burst_buffer[j+1] = Colour;
}

uint32_t Sending_Size = Size<<1;
uint32_t Sending_in_Block = Sending_Size/Buffer_Size;
uint32_t Remainder_from_block = Sending_Size%Buffer_Size;

TFT_DC_SET;
TFT_CS_RESET;

if(Sending_in_Block > 0){
	for(uint32_t j = 0; j < (Sending_in_Block); j++){
		HAL_SPI_Transmit(&hspi1, (unsigned char *)burst_buffer, Buffer_Size, 100);
		//ILI9341_SPI_Send_NByte(burst_buffer, Buffer_Size);
	}
}

//REMAINDER!
if(Remainder_from_block >0){
	HAL_SPI_Transmit(&hspi1, (unsigned char *)burst_buffer, Remainder_from_block, 100);
	//ILI9341_SPI_Send_NByte(burst_buffer, Remainder_from_block);
}

TFT_CS_SET;

}


void LCD_fillRect1(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t Colour)
{
ILI9341_Write_Command(0x2A);    //X
ILI9341_Write_Data(x1>>8);
ILI9341_Write_Data(x1);
ILI9341_Write_Data((x2-1)>>8);
ILI9341_Write_Data((x2-1)&0xFF);

ILI9341_Write_Command(0x2B);    //Y
ILI9341_Write_Data(y1>>8);
ILI9341_Write_Data(y1);
ILI9341_Write_Data((y2-1)>>8);
ILI9341_Write_Data((y2-1)&0xFF);

ILI9341_Write_Command(0x2C);

uint32_t j;
uint32_t Size = (x2-x1)*(y2-y1);
uint32_t Buffer_Size;

Buffer_Size=400;

unsigned char chifted = Colour>>8;
unsigned char burst_buffer[Buffer_Size];
for(j = 0; j < Buffer_Size; j+=2){
		burst_buffer[j] = chifted;
		burst_buffer[j+1] = Colour;
}

uint32_t Sending_Size = Size<<1;
uint32_t Sending_in_Block = Sending_Size/Buffer_Size;
uint32_t Remainder_from_block = Sending_Size%Buffer_Size;

TFT_DC_SET;
TFT_CS_RESET;

if(Sending_in_Block > 0){
	for(uint32_t j = 0; j < (Sending_in_Block); j++){
		HAL_SPI_Transmit(&hspi1, (unsigned char *)burst_buffer, Buffer_Size, 100);
		//ILI9341_SPI_Send_NByte(burst_buffer, Buffer_Size);
	}
}

//REMAINDER!
if(Remainder_from_block >0){
	HAL_SPI_Transmit(&hspi1, (unsigned char *)burst_buffer, Remainder_from_block, 100);
	//ILI9341_SPI_Send_NByte(burst_buffer, Remainder_from_block);
}

TFT_CS_SET;

}

void LCD_init(){
       
   // LCD_pinsInit();    
   // dmaInit();
    LCD_reset();  
    
    LCD_setSpi8();        
    LCD_exitStandby();
    LCD_configure();

    //TFT_LED_SET;
}

//</editor-fold>

//<editor-fold desc="LCD common operations">

void LCD_setOrientation(uint8_t o) {
    if (o == ORIENTATION_LANDSCAPE || o == ORIENTATION_LANDSCAPE_MIRROR) {
        screen_height = LCD_PIXEL_WIDTH;
        screen_width  = LCD_PIXEL_HEIGHT;
    } else {
        screen_height = LCD_PIXEL_HEIGHT;
        screen_width  = LCD_PIXEL_WIDTH;
    }
    TFT_CS_RESET;
    dmaSendCmdCont(LCD_MAC);
    dmaSendDataCont8(&o, 1);
    TFT_CS_SET;
}

inline void LCD_setAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    uint16_t pointData[2];

    TFT_CS_RESET;
    dmaSendCmdCont(LCD_COLUMN_ADDR);
    pointData[0] = x1;
    pointData[1] = x2;
    LCD_setSpi16();
    dmaSendDataCont16(pointData, 2);
    LCD_setSpi8();

    dmaSendCmdCont(LCD_PAGE_ADDR);
    pointData[0] = y1;
    pointData[1] = y2;
    LCD_setSpi16();
    dmaSendDataCont16(pointData, 2);
    LCD_setSpi8();
    TFT_CS_SET;
}

inline uint16_t LCD_getWidth() {
    return screen_width;
}

inline uint16_t LCD_getHeight() {
    return screen_height;
}

//</editor-fold>

//<editor-fold desc="SPI functions">
//inline
 inline void LCD_setSpi8(void) {
    //TFT_RST_SET;
    SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
//    SPI_MASTER->CR1 &= ~SPI_CR1_DFF; // SPI 8
    SPI_MASTER->CR2 &= ~SPI_CR2_DS_3;
    SPI_MASTER->CR2 |= SPI_CR2_DS_0|SPI_CR2_DS_1|SPI_CR2_DS_2;
    SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
    //TFT_RST_RESET;
      
}

 //inline
inline void LCD_setSpi16(void) {
    SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
    //SPI_MASTER->CR1 |= SPI_CR1_DFF;  // SPI 16
    SPI_MASTER->CR2 |= SPI_CR2_DS_0|SPI_CR2_DS_1|SPI_CR2_DS_2|SPI_CR2_DS_3;
    SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI   
}

// </editor-fold>
