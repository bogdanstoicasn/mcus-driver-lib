#ifndef USART_DRIVER_H
#include USART_DRIVER_H

#include "macros32f103.h"

typedef struct {

} usart1_def;

void usart1_init(void);

void usart1_transmit_byte(uint8_t data);

void usart1_receive_byte(void);

#endif
