#include "../include/twi_driver.h"

static uint8_t twi_start(void)
{
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);

	/* Wait for TWINT to set */
	while (!(TWCR & (1 << TWINT)));

	/* 0x08 = start condition has been transmitted 
	 * 0x10 = repeat the start condition
	 */
	if (TWI_STATUS != 0x10 && TWI_STATUS != 0x08)
		return TWI_STATUS;
	
	return STATUS_SUCCESS;
}

static uint8_t twi_stop(void)
{
	TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);

	/* Wait for the transmission of the stop condition */
	while (TWCR & (1 << TWSTO));

	return STATUS_SUCCESS; 
}

static uint8_t twi_write_slaveaddr(uint8_t addr)
{
	TWDR = addr;

	TWCR = (1 << TWINT) | (1 << TWEN);

	while (!(TWCR & (1 << TWINT)));

	/*
	 * 0x18 = SLA+W has been transmitted, ack received
	 * 0x40 = SLA+R has been transmitted, ack received
	 * */
	if (TWI_STATUS != 0x18 && TWI_STATUS != 0x40)
		return TWI_STATUS;

	return STATUS_SUCCESS;
}

static uint8_t  twi_write(uint8_t data)
{
	TWDR = data;

	TWCR = (1 << TWINT) | (1 << TWEN);

	while (!(TWCR & (1 << TWINT)));

	if (TWI_STATUS != 0x28)
		return TWI_STATUS;

	return STATUS_SUCCESS;
}

static uint8_t twi_read(uint8_t ack)
{
	if (ack) {
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

		while (!(TWCR & (1 << TWINT)));

		if (TWI_STATUS != 0x50)
			return TWI_STATUS;
	} else {
		TWCR = (1 << TWINT) | (1 << TWEN);

		while (!(TWCR & (1 << TWINT)));

		if (TWI_STATUS != 0x58)
			return TWI_STATUS;
	}

	uint8_t data = TWDR;

	return data;
}

static uint8_t twi_init(twi_freq_mode freq, uint8_t pullup)
{
	DDRC |= (1 << TWI_SCL_PIN) | (1 << TWI_SDA_PIN);

	if (pullup)
		PORTC |= (1 << TWI_SCL_PIN) | (1 << TWI_SDA_PIN);
	else
		PORTC &= ~((1 << TWI_SCL_PIN) | (1 << TWI_SDA_PIN));

	DDRC &= ~((1 << TWI_SCL_PIN) | (1 << TWI_SDA_PIN));

	switch (freq) {
		case twi_freq_100k:
			/* 16/(16 + 2*72) == 100khz */
			TWBR = 72;
			break;
		case twi_freq_250k:
			/* 16/(16+2*24) == 250khz*/
			TWBR = 24;
			break;
		case twi_freq_400k:
			/* 16/(16+2*12) == 400khz */
			TWBR = 12;
			break;
		default:
			break;
	}

	return STATUS_SUCCESS;
}

