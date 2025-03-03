#include "../include/spi_driver.h"

uint16_t spi_master_receive(void)
{
	SPI1->dr = 0xFF;

	/* Wait for RXNE */
	while (!(SPI1->sr & (1 << 0)));

	return (uint16_t)SPI1->dr;
}

uint16_t spi_slave_receive(void)
{
	while (!(SPI1->sr & (1 << 0))) ;
	
	return (uint16_t)SPI1->dr;
}
