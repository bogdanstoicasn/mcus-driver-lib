#include "../include/twi_driver.h"

static uint8_t twi_start(void)
{
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);

	/* Wait for TWINT to set */
	while (!(TWCR & (1 << TWINT)));

	/* 0x08 = start condition has been transmited 
	 * 0x10 = repeat the start condition
	 */
	if (TWI_STATUS != 0x10 && TWI_STATUS != 0x08)
		return TWI_STATUS;
	
	return STATUS_SUCCESS;
}

static uint8_t twi_stop(void)
{
	TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);

	/* Wait for the transmition of the stop condition */
	while (TWCR & (1 << TWSTO));

	return STATUS_SUCCESS; 
}
