#include "../include/wdt_driver.h"

void wdt_disable()
{
	DISABLE_INTERRUPTS();

	WDT_RESET();

	MCUSR &= ~(1 << WDRF);

	/* keep basic settings to avoid unintentional timeout*/
	WDTCSR |= (1 << WDCE) | (1 << WDE);

	WDTCSR = 0x00;

	ENABLE_INTERRUPTS();
}

void wdt_enable(wdt_prescaler value)
{
	DISABLE_INTERRUPTS();

	WDTCSR |= (1 << WDCE) | (1 << WDE);
	
	if (value == PRESCALER_16MS) {
		WDTCSR = (1 << WDE);
		return;
	}

	WDTCSR = (1 << WDE) | value;

	ENABLE_INTERRUPTS();
}

