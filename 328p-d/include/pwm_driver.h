#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include "macros328p.h"
// if you want clean config uncomment the line below
#define CLEAN 

typedef enum {
	PRESCALER_1 = (1 << CS00),
	PRESCALER_8 = (1 << CS01),
	PRESCALER_64 = (1 << CS00) | (1 << CS01),
	PRESCALER_256 = (1 << CS02),
	PRESCALER_1024 = (1 << CS00) | (1 << CS02)
} pwm_prescaler;

typedef enum {
	MODE_FAST,
	MODE_PHASE_CORRECT
} pwm_mode;

uint8_t tc0_pwm_init(pwm_mode mode, pwm_prescaler prescaler, uint8_t duty_cycle);

#endif
