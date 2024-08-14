#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include "macros328p.h"

#define BAUDRATE       9600
#define F_CPU          16000000UL
#define BAUD_PRESCALER ((F_CPU / (BAUDRATE * 16UL)) - 1)

/*              General macros               */

/* Parity for usart init */
#define EVEN_PARITY    2
#define ODD_PARITY     3
#define DEFAULT_PARITY 0

/* Number of stop bits for usart init */
#define DEFAULT_STOP   1
#define COMPLEX_STOP   2

void usart_init(uint8_t parity, uint8_t stop);

/* Receive a byte
 *
 * TODO: check for other flags in UCSR0A
 */
uint8_t usart_receive_byte(void);

/* Transmite byte 
 *
 * TODO: maybe check for errors in ch
 */
uint8_t usart_transmite_byte(uint8_t ch);

/* Usart disable 
 *
 * Usage: just for critical op. 
 * */
void usart_disable(void);


#endif

