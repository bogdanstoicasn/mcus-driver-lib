#ifndef WDT_DRIVER_H
#define WDT_DRIVER_H

#include "./util/atm328p_asm.h"
#include "./util/atm328p_base.h"

typedef enum {
	PRESCALER_16MS = 0,
	PRESCALER_32MS = (1 << WDP0),
	PRESCALER_64MS = (1 << WDP1),
	PRESCALER_125MS = (1 << WDP0) | (1 << WDP1), /* 0.125s */
	PRESCALER_250MS = (1 << WDP2), /* 0.25s*/
	PRESCALER_500MS = (1 << WDP0) | (1 << WDP1), /* 0.5s */
	PRESCALER_1S = (1 << WDP1) | (1 << WDP2),
	PRESCALER_2S = (1 << WDP0) | (1 << WDP1) | (1 << WDP2),
	PRESCALER_4S = (1 << WDP3),
	PRESCALER_8S = (1 << WDP0) | (1 << WDP3)
} wdt_prescaler;

void wdt_disable(void);

void wdt_enable(wdt_prescaler value);

#endif
