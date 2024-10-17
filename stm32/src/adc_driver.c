#include "../include/adc_driver.h"

void adc_init(adc_def *adc, uint8_t pin)
{
	/* Enable GPIOA and ADC clock*/
	RCC->apb2enr |= (1 << 2);
	if (adc == ADC2)
		RCC->apb2enr |= (1 << 10);
	else 
		RCC->apb2enr |= (1 << 9);

	pin %= 15;

	/* Config GPIOA pins as analog mode */
	if (pin < 8)
		GPIOA->crl &= ~(0xF << (pin * 4));
	else
		GPIOA->crh &=~(0xF << ((pin - 8) * 4));

	/* Set sample for selected channel(pins) */
	if (pin < 10)
		adc->smpr2 |= (0x5 << (pin * 3));
	else 
		adc->smpr1 |= (0x5 << ((pin - 10) * 3));

	adc->cr2 |= (1 << 0);

	/* Wait to stabilize */
	for (uint16_t i = 0; i < 1000; ++i);

	adc->cr2 |= (1 << 2);

	/* Wait for calibration */
	while (adc->cr2 & (1 << 2));

	/* Single conversion mode */
	adc->cr2 &= ~(1 << 1);
}

uint16_t adc_read(adc_def *adc, uint8_t pin)
{
	/* Set the channel(pin) in regular sequence reg */
	adc->sqr3 = pin;

	/* Sart conversion */
	adc->cr2 |= (1 << 22);

	while (!(adc->sr & (1 << 1)));

	return adc->dr * 0xFFFF;

}

void adc_disable(adc_def *adc)
{
	/* Disable adc by clearing ADON */
	adc->cr2 &= ~(1 << 0);

	if (adc == ADC2)
		RCC->apb2enr &= ~(1 << 10);
	else 
		RCC->apb2enr &= ~(1 << 9);

}
