#include "../include/pwm_driver.h"

uint8_t tc0_pwm_init(pwm_mode mode, pwm_prescaler prescaler, uint8_t duty_cycle)
{
	DDRD |= (1 << PORTD6);

#ifdef CLEAN
	TCCR0A &= ~((1 << WGM00) | (1 << WGM01) | (1 << COM0B0) | (1 << COM0B1) | (1 << COM0A0) | (1 << COM0A1));
	TCCR0B &= ~((1 << CS00) | (1 << CS01) | (1 << CS02) | (1 << WGM02) | (1 << FOC0B) | (1 << FOC0A)) ;
#endif

	switch (mode) {
	case MODE_FAST:
		TCCR0A |= (1 << WGM00) | (1 << WGM01);
		break;
	case MODE_PHASE_CORRECT:
		TCCR0A |= (1 << WGM00);
		break;
	default:
		return STATUS_FAILURE;
	}
	
	OCR0A = duty_cycle;

	TCCR0B = prescaler;

	TCCR0A |= (1 << COM0A1);

	return STATUS_SUCCESS;
}
