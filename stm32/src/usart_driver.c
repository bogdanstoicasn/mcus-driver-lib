#include "../include/usart_driver.h"

/* USART1 / USART2 / USART3 configs */
static const usart_config usart_configs[] = {
	{GPIOA, USART1, (1 << 2), (1 << 14), 9, 10},
	{GPIOA, USART2, (1 << 2), (1 << 17), 2, 3},
	{GPIOB, USART3, (1 << 3), (1 << 18), 10, 11}
};

void usart_init(usart_def *usartx, uint32_t baudrate, uint32_t clock)
{
	const usart_config *conf = (void *)0;
	for (uint8_t i = 0; i < sizeof(usart_configs) / sizeof(usart_configs[0]); ++i) {
		if (usart_configs[i].usart == usartx) {
			conf = &usart_configs[i];
			break;
		}
	}

	if (!conf) {
		/* TODO:  maybe check for err codes*/
		return;
	}
	
	RCC->apb2enr |= conf->gpio_en;

	if (usartx == USART1)
		RCC->apb2enr |= conf->usart_en;
	else 
		RCC->apb1enr |= conf->usart_en;

	/* Configure TX pin as alternate function push-pull
	 * Step 1: clear bits
	 * Step 2: set speed to 50MHz
	 */
	if (conf->tx < 8) {
		conf->gpio->crl &= ~(0xF << (conf->tx * 4));
		conf->gpio->crl |= (0xB << (conf->tx * 4));
	} else {
		conf->gpio->crh &= ~(0xF << ((conf->tx - 8) * 4));
		conf->gpio->crh |= (0xB << ((conf->tx - 8) * 4));
	}

	/* Configure RX pin as input floating
	 * Step 1: clear bits
	 * Step 2: input floating 
	 */
	if (conf->rx < 8) {
		conf->gpio->crl &= ~(0xF << (conf->rx * 4));
		conf->gpio->crl |= (0x4 << (conf->rx * 4));
	} else {
		conf->gpio->crl &= ~(0xF << ((conf->rx - 8) * 4));
		conf->gpio->crl |= (0x4 << ((conf->rx - 8) * 4));
	}

	/* Reser USART config and enable the USART */
	usartx->cr1 = 0x00;
	usartx->cr1 |= (1 << 13);
	usartx->cr1 &= ~(1 << 12);

	/* Set 1 stop bit and disable hardware flow control */
	usartx->cr2 = 0x00;
	usartx->cr3 = 0x00;

	usartx->brr = ((clock + (baudrate /2U)) / baudrate);

	/* Enable transmitter and receiver */
	usartx->cr1 |= (1 << 3) | (1 << 2);
}

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

void usart_basic_config(usart_def *usartx, uint8_t stopbits)
{
	/* Stop bits config */
	switch (stopbits) {
	case 1:
		usartx->cr2 = 0x00;
		break;
	case 2:
		usartx->cr2 |= (1 << 13);
		break;
	default:
		break;
	}
	
}
