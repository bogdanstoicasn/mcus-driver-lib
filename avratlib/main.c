#include <util/delay.h>

#define USER_ISR
#include "avratlib.h"

char *strin = "Hello\n";

void test_usart(void)
{
	usart_config myusart = {
		.f_cpu = 16000000,
		.baudrate = 9600,
		.baudprescaler = 0,
		.datasize = DATA_SIZE_8BIT,
		.interruptmode = USART_INT_DISABLED,
		.operationmode = ASYNCH_MODE,
		.rxtx = RXTX_ENABLE,
		.paritymode = EVEN_MODE,
		.stopbits = COMPLEX_STOP,
		.edge = RISING_EDGE
	};
	usart_init(&myusart);
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
	wdt_enable(WDT_PRESCALER_4S, WDT_MODE_INTERRUPT);
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

void test_pwm()
{
	tc0_pwm_init(MODE_FAST, PRESCALER_1024, 0x80);
}

void test_adc()
{
	adc_init(0, PRESC_VAL_32, AVCC_EXT_CAPACITOR_AREF_PIN);
	uint8_t counter = 0;
	while (1) {
		uint16_t adc_val = adc_read();
		usart_send_hex(adc_val);
		_delay_ms(1000);
		if (counter++ == 10) {
			adc_disable();
			break;
		}
	}
}

int main()
{

	test_usart();
	test_eeprom();
	test_twi();
	test_pwm();
	test_adc();
	test_wdt();

    while (1) {

    }

    return 0;
}
