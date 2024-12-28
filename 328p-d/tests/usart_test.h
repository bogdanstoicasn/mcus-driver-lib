#ifndef USART_TEST_H
#define USART_TEST_H

#include "../include/usart_driver.h"

inline void test1_usart()
{
	usart_init(DEFAULT_PARITY, DEFAULT_STOP);
	usart_transmit_byte('C');

	uint8_t ch = usart_receive_byte();

	usart_transmit_byte(ch);
}

#endif
