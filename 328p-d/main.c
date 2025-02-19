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
	
	/* Echo test */
	uint8_t data = 0;
	while (1) {
		data = usart_receive_byte();
		usart_transmit_byte(data + 1);
		if (data == 'q') {
			usart_transmit_byte('\n');
			break;
		}
	}
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

// Watchdog interrupt vector for WDT interrupt
void __vector_6(void) __attribute__ ((signal, used));
void __vector_6(void)
{
    // Toggle LED on pin PD7 (example LED on an ATmega328P board)
    gpio_toggle(&PORTD, PORTD7);

    // Optionally reset the watchdog timer if needed (if the interrupt is to refresh the WDT)
    // WDT_RESET();
}

void test_wdt()
{
	gpio_setup(&DDRD, PORTD7, OUT);
	wdt_enable(WDT_PRESCALER_1S, WDT_MODE_INTERRUPT);
}

int main()
{

	test_usart();
	test_eeprom();
	test_wdt();

    while (1) {

    }

    return 0;
}
