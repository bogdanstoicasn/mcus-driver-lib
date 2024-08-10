#include "../include/led_driver.h"

void led_setup()
{
	DDRB |= (1 << LED_BUILTIN);
}

void led_toggle()
{
	PORTB ^= (1 << LED_BUILTIN);
}
