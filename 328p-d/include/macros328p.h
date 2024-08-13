#ifndef MACROS_328P_H
#define MACROS_328P_H

#include <stdint.h>

/* General use macros */
#define IN_PULLUP 2
#define OUT     1
#define IN      0

#define ON      1
#define OFF     0

#define BIT0    0
#define BIT1    1
#define BIT2    2
#define BIT3    3
#define BIT4    4
#define BIT5    5
#define BIT6    6
#define BIT7    7

#define STATUS_SUCCESS 0
#define STATUS_FAILURE 1


/* Status register */
#define SREG    (*(volatile uint8_t *)0x5F)

#define PORTD   (*(volatile uint8_t *)0x2B)
#define PORTD0  0
#define PORTD1  1
#define PORTD2  2
#define PORTD3  3
#define PORTD4  4
#define PORTD5  5
#define PORTD6  6
#define PORTD7  7

#define DDRD    (*(volatile uint8_t *)0x2A)
#define DDD0    0
#define DDD1    1
#define DDD2    2
#define DDD3    3
#define DDD4    4
#define DDD5    5
#define DDD6    6
#define DDD7    7

#define PIND    (*(volatile uint8_t *)0x29)
#define PIND0   0
#define PIND1   1
#define PIND2   2
#define PIND3   3
#define PIND4   4
#define PIND5   5
#define PIND6   6
#define PIND7   7



#define PORTC   (*(volatile uint8_t *)0x28)
#define PORTC0  0
#define PORTC1  1
#define PORTC2  2
#define PORTC3  3
#define PORTC4  4
#define PORTC5  5
#define PORTC6  6

#define DDRC    (*(volatile uint8_t *)0x27)
#define DDC0    0
#define DDC1    1
#define DDC2    2
#define DDC3    3
#define DDC4    4
#define DDC5    5
#define DDC6    6

#define PINC    (*(volatile uint8_t *)0x26)
#define PINC0   0
#define PINC1   1
#define PINC2   2
#define PINC3   3
#define PINC4   4
#define PINC5   5
#define PINC6   6



#define PORTB   (*(volatile uint8_t *)0x25)
#define PORTB0  0
#define PORTB1  1
#define PORTB2  2
#define PORTB3  3
#define PORTB4  4
#define PORTB5  5
#define PORTB6  6
#define PORTB7  7

#define DDRB    (*(volatile uint8_t *)0x24)
#define DDB0    0
#define DDB1    1
#define DDB2    2
#define DDB3    3
#define DDB4    4
#define DDB5    5
#define DDB6    6
#define DDB7    7

#define PINB    (*(volatile uint8_t *)0x23)
#define PINB0   0
#define PINB1   1
#define PINB2   2
#define PINB3   3
#define PINB4   4
#define PINB5   5
#define PINB6   6
#define PINB7   7

/* USART macros */
#define UDR0    (*(volatile uint8_t *)0xC6)
#define UBRR0H  (*(volatile uint8_t *)0xC5)
#define UBRR0L  (*(volatile uint8_t *)0xC4)

#define UCSR0C  (*(volatile uint8_t *)0xC2)
#define UCPOL0  0
#define UCBZ00  1
#define UCBZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

#define UCSR0B (*(volatile uint8_t *)0xC1)
#define TXB80  0
#define RXB80  1
#define UCSZ02 2
#define TXEN0  3
#define RXEN0  4
#define UDRIE0 5
#define TXCIE0 6
#define RXCIE0 7

#define UCSR0A (*(volatile uint8_t *)0xC0)
#define MPCM0  0
#define U2X0   1
#define UPE0   2
#define DOR0   3
#define FE0    4
#define UDRE0  5
#define TXC0   6
#define RXC0   7

#endif
