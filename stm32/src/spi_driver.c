#include "../include/spi_driver.h"

void spi_init(volatile spi_config *hspi)
{
	/* Disable SPI */
	hspi->SPIx->cr1 &= ~(1 << 6);

	if (hspi->priority == SPI_MASTER_CONFIG)
		hspi->SPIx->cr1 |= (1 << 2);
	else
		hspi->SPIx->cr1 &= ~(1 << 2);

	/* Only in master mode */
	hspi->SPIx->cr1 &= ~(0x07 << 3);
	hspi->SPIx->cr1 |= (hspi->prescaler << 3);

	if (hspi->cpol)
		hspi->SPIx->cr1 |= (1 << 1);
	else 
		hspi->SPIx->cr1 &= ~(1 << 1);

	if (hspi->cpha)
		hspi->SPIx->cr1 |= (1 << 0);
	else 
		hspi->SPIx->cr1 &= ~(1 << 0);

	if (hspi->dataform == SPI_DATA_16BIT)
		hspi->SPIx->cr1 |= (1 << 11);
	else 
		hspi->SPIx->cr1 &= ~(1 << 11);

	/* Enable SPI */
	hspi->SPIx->cr1 |= (1 << 6);
}

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
