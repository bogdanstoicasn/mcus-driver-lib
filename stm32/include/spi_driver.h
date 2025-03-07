#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "./util/stm32f103_def.h"

typedef enum {
	SPI_MODE_POLLING = 0,
	SPI_MODE_INTERRUPT = 1
} spi_mode;

typedef struct {
	volatile spi_def *SPIx;
	uint8_t spi_num; /* used for easy debugging */
	spi_mode mode;
} spi_config;

/* Master section */

void spi_master_init(volatile spi_config *hspi);

uint16_t spi_master_receive(volatile spi_config *hspi);

void  spi_master_transmit(volatile spi_config *hspi, uint16_t data);


/* Slave section */

void spi_slave_init(volatile spi_config *hspi);

uint16_t spi_slave_receive(volatile spi_config *hspi);

void spi_slave_transmit(volatile spi_config *hspi, uint16_t data);

#endif
