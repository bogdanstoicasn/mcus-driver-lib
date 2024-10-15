#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include "./util/stm32f103_def.h"

void usart_init(usart_def *usartx);

void usart_transmit_byte(usart_def *usartx, uint8_t data);

uint8_t usart_receive_byte(usart_def *usartx);

#endif
