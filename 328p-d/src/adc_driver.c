#include "../include/adc_driver.h"

void adc_init(uint8_t pin, uint8_t prescaler, uint8_t ref_voltage)
{
	/* Power on ADC */
	PRR &= ~(1 << PRADC);

	/* Start the ADC */
	ADCSRA |= (1 << ADEN);

	/* Set the prescaler */
	ADCSRA = (ADCSRA & ~7) | (prescaler & 7);

	/* Set the reference voltage */
	if (ref_voltage == 2 || ref_voltage > 2)
		ref_voltage = AVCC_EXT_CAPACITOR_AREF_PIN;

	ADMUX = (ADMUX & ~(1 << REFS1 | 1 << REFS0)) | (ref_voltage << REFS0);

	/* 
	 * Set the channel(pin)
	 * Ignore reserved bits
	 * MUX3 can be ignored sometimes because is only used for
	 * differential inputs or internal channels
	 */
	if (!((pin <= 7) || pin == 0x0E || pin == 0x0F))
		pin = 0;

	ADMUX = (ADMUX & ~(1 << MUX0 | 1 << MUX1 | 1 << MUX2 | 1 << MUX3)) | (pin & 0x0F);
}

void adc_disable(void)
{
	/* 
	 * Disable ADC in the control register 
	 * Disclaimer: it stops the current conversion
	 */
	ADCSRA &= ~(1 << ADEN);

	/* Shutdown the ADC from the power reduction register */
	PRR |= (1 << PRADC);
}

uint16_t adc_read(void)
{
	/* Start the conversion */
	ADCSRA |= (1 << ADSC);
	
	while (ADCSRA & (1 << ADSC));

	/* 
	 * First we get the low value!
	 * If high is checked first the both low and high regs will be reset
	 */
	uint8_t low = ADCL;
	uint8_t high = ADCH;

	uint16_t adc_val = (high << 8) | low;

	return adc_val;
}
