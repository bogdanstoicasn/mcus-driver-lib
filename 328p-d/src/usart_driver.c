#include "../include/usart_driver.h"


void usart_init(uint8_t parity, uint8_t stop)
{
	/* Load lower and upper bits of the baud rate */
	UBRR0L = (uint8_t)(BAUD_PRESCALER);
	UBRR0H = (uint8_t)(BAUD_PRESCALER >> 8);

	/* Configure for transmite and receive */
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);

	/* Set size of 8 bits */
	UCSR0C |= (1 << UCBZ00) | (1 << UCBZ01);

	/* Check if it's async mode */
	UCSR0C &= ~(1 << UMSEL00) & ~(1 << UMSEL01);

	 /* Disable double speed */
	UCSR0A &= ~(1 << U2X0);

	/* Check for parity
	 * 2 = even parity
	 * 3 = odd parity
	 * deafult = no parity
	 */
	switch (parity) {
	case 2:
		UCSR0C |= (1 << UPM01);
		break;
	case 3:
		UCSR0C |= (1 << UPM01) | (1 << UPM00);
		break;
	default:
        UCSR0C &= ~(1 << UPM00) & ~(1 << UPM01);
		break;
	}

	/* Check for stop bits */
	UCSR0C = (UCSR0C & ~(1 << USBS0)) | ((stop == 2) << USBS0);
	
}

uint8_t  usart_receive_byte(void)
{
	while (!(UCSR0A & (1 << RXC0)));

	return UDR0;
}

uint8_t usart_transmite_byte(uint8_t ch)
{
	while (!(UCSR0A & (1 << UDRE0)));

	UDR0 = ch;

	return STATUS_SUCCESS;
}

/* Use for critical operations
 * For everyday project is obsolete
 * */
void usart_disable(void)
{
	/* Disable the transm and recv */
	UCSR0B &= ~((1 << TXEN0) | (1 << RXEN0));

	/* Clear flags*/
	UCSR0A = 0;

	/* Reset baud rate */
	UBRR0L = 0;
	UBRR0H = 0;

	/* Clear other stuff */
	UCSR0C = 0;
}
