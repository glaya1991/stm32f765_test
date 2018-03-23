/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include  <errno.h>
#include  <sys/unistd.h>
#include "usart.h"

int _write(int file, char *data, int len)
{
    if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
    {
        errno = EBADF;
        return(-1);
    }
    HAL_StatusTypeDef StatusTransmit = HAL_OK;
    StatusTransmit = HAL_UART_Transmit(&huart1, (uint8_t *)data, len, 1000);
    return(StatusTransmit == HAL_OK ? len : 0);
}
