#ifndef TEST2_CONTROL_H
#define TEST2_CONTROL_H

#include "config.h"
#include "commands.h"

// <editor-fold desc="Functions">
#define TFT_DC_SET      HAL_GPIO_WritePin(GPIOA, TFT_DC_PIN, SET);
#define TFT_DC_RESET    HAL_GPIO_WritePin(GPIOA, TFT_DC_PIN, RESET);

#define TFT_RST_SET     HAL_GPIO_WritePin(GPIOA, TFT_RESET_PIN, SET);
#define TFT_RST_RESET   HAL_GPIO_WritePin(GPIOA, TFT_RESET_PIN, RESET);

#define TFT_CS_SET      HAL_GPIO_WritePin(GPIOA, TFT_CS_PIN, SET);
#define TFT_CS_RESET    HAL_GPIO_WritePin(GPIOA, TFT_CS_PIN, RESET);

#define TFT_LED_SET      HAL_GPIO_WritePin(GPIOA, TFT_LED_PIN, SET);
#define TFT_LED_RESET    HAL_GPIO_WritePin(GPIOA, TFT_LED_PIN, RESET);
// </editor-fold>

#endif //TEST2_CONTROL_H
