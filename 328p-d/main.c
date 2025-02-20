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

void usart_send_hex(uint8_t num)
{
    uint8_t high_nibble = (num >> 4) & 0x0F;
    uint8_t low_nibble = num & 0x0F;

    usart_transmit_byte('0'); 
    usart_transmit_byte('x');

    usart_transmit_byte(high_nibble < 10 ? '0' + high_nibble : 'A' + (high_nibble - 10));
    usart_transmit_byte(low_nibble < 10 ? '0' + low_nibble : 'A' + (low_nibble - 10));

    usart_transmit_byte('\n');
}

void test_twi()
{
	/* The function sets the required ports as input too */
	twi_init(twi_freq_100k, 1);

	uint8_t err;
	uint8_t test_addr = 'A';

	/* Check for the address */
	for (uint8_t addr = 0x00; addr < 0x80; addr++) {
		err = twi_master_tx(&test_addr, 1, addr, 0);

		if (err == STATUS_SUCCESS) {
			usart_transmit_byte('Y');
			usart_transmit_byte('-');
			usart_send_hex(addr);
			test_addr = addr;
			break;
		}
	}

	/* Send strin and see the responses */
	uint8_t received_data[6] = {0};
	err = twi_master_tx((uint8_t *)strin, 6, test_addr, 0);
	if (err) {
		usart_transmit_byte('N');
		usart_transmit_byte('\n');
	}
	err = twi_master_rx(received_data, 6, test_addr);
	if (err) {
		usart_transmit_byte('N');
		usart_transmit_byte('\n');
	}

	for (uint8_t i = 0; i < 6; i++) {
		usart_send_hex(received_data[i]);
	}
	
}

int main()
{

	test_usart();
	test_eeprom();
	test_twi();
	test_wdt();

    while (1) {

    }

    return 0;
}
