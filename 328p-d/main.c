#include <util/delay.h>
#include "328p-d.h"

char *strin = "Hello\n";

void test_usart(void)
{
	usart_init(EVEN_PARITY, DEFAULT_STOP);
	_delay_ms(2000);
	
	for (uint8_t i = 0; i < 6; i++){
		usart_transmit_byte(strin[i]);
	}

	uint8_t data = usart_receive_byte();
	if (data == 'y') usart_transmit_byte('Y');
	else usart_transmit_byte('N');
}

void test_eeprom()
{
	if (eeprom_read(0x00) != 0xFF) goto write_done;
	for (uint8_t i = 0; i < 6; i++) {
		eeprom_write((uint16_t)i, strin[i]);
	}
write_done:
	
	;

	uint8_t data = 0;
	for (uint8_t i = 0; i < 6; i++) {
		data = eeprom_read((uint16_t)i);
		usart_transmit_byte(data);
	}

}
// vect 6 in table(don't forget)
void test_wdt()
{
	gpio_setup(&DDRD, PORTD7, OUT);
	gpio_write(&PORTD, PORTD7, OUT);
	
	while(1) {
		_delay_ms(1000);
		gpio_toggle(&PORTD, PORTD7);
	}
}

/*
 * Define ISR manually 
 */


int main()
{

	test_usart();
	test_eeprom();
	test_wdt();
	while(1) {
		_delay_ms(2000);
	}

	return 0;
}
