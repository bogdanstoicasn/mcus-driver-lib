#include "../include/usart_driver.h"

void usart_transmit_byte(usart_def *usartx, uint8_t data)
{
	/* Wait until transmit data register is empty(TXE set)*/
	 while (!(usartx->sr & (1 << 7)));

 	 usartx->dr = data;

 	 /* Wait until transmission is complete */
 	 while (!(usartx->sr & (1 << 6)));
}

uint8_t usart_receive_byte(usart_def *usartx)
{
	/* Wait until data is received (RXNE bit set)*/
	while (!(usartx->sr & (1 << 5)));

	return (uint8_t)usartx->dr;
}
