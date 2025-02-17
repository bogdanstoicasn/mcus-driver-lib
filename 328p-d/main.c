#include <util/delay.h>
#include "328p-d.h"

void TEST_usart(void)
{
	usart_init(DEFAULT_PARITY, DEFAULT_STOP);
	_delay_ms(2000);
	
	char *strin = "Hello";
	for (uint8_t i = 0; i < 5; i++){
		_delay_ms(2000);
		usart_transmit_byte(strin[i]);
	}

	uint8_t data = usart_receive_byte();
	if (data == 'y') usart_transmit_byte('Y');
	else usart_transmit_byte('N');
}

int main()
{

	TEST_usart();
	while(1) {
		_delay_ms(2000);
	}

	return 0;
}
