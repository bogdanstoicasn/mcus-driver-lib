#include "../include/spi_driver.h"

void spi_master_transmit(volatile spi_config *hspi, uint16_t data)
{
	while (!(hspi->SPIx->sr &  (1 << 1)));

	hspi->SPIx->dr = data;

	while (!(hspi->SPIx->sr & (1 << 0)));

	while (hspi->SPIx->sr & (1 << 7));
}

uint16_t spi_master_receive(volatile spi_config *hspi)
{
	hspi->SPIx->dr = 0xFF;
	/* Wait for RXNE */
	while (!(hspi->SPIx->sr & (1 << 0)));

	return (uint16_t)hspi->SPIx->dr;
}

/* Slave section */
void spi_slave_transmit(volatile spi_config *hspi, uint16_t data)
{
	while (!(hspi->SPIx->sr & (1 << 1)));

	hspi->SPIx->dr = data;
}

uint16_t spi_slave_receive(volatile spi_config *hspi)
{
	while (!(hspi->SPIx->sr & (1 << 0)));
	
	return (uint16_t)hspi->SPIx->dr;
}
