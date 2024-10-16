#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include "./util/stm32f103_def.h"

#define APB2_CLK 72000000
#define APB1_CLK 36000000

/* Desired baudrate, can be changed */
#define BAUDRATE 115200

/* USART configuration holder */
typedef struct {
	gpio_def *gpio;
	usart_def *usart;

	uint32_t gpio_en;
	uint32_t usart_en;

	uint8_t tx;
	uint8_t rx;

} usart_config;

/* TODO: stop bit function and tx/rx function */

void usart_init(usart_def *usartx, uint32_t baudrate, uint32_t clock);

void usart_transmit_byte(usart_def *usartx, uint8_t data);

uint8_t usart_receive_byte(usart_def *usartx);


void usart_basic_config(usart_def *usartx, uint8_t stopbits);

#endif
