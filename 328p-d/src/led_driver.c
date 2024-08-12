#include "../include/led_driver.h"

void led_setup(uint8_t port, uint8_t pin)
{
	switch (port) {
	case PORT_B:
		DDRB |= (OUT << pin);
		break;
	case PORT_C:
		DDRC |= (OUT << pin);
		break;
	case PORT_D:
		DDRD |= (OUT << pin);
		break;
	default:
		break;
	}
}

void led_toggle(uint8_t port, uint8_t pin, uint8_t state)
{
    switch (port) {
    case PORT_B:
        SET_PIN_STATE(PORTB, pin, state);
        break;
    case PORT_C:
        SET_PIN_STATE(PORTC, pin, state);
        break;
    case PORT_D:
        SET_PIN_STATE(PORTD, pin, state);
        break;
    default:
        break;
    }
}
