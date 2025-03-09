#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "./util/stm32f103_def.h"

#define SPI_MASTER_CONFIG 0
#define SPI_SLAVE_CONFIG  1

#define SPI_DATA_8BIT  0
#define SPI_DATA_16BIT 1

typedef enum {
	SPI_MODE_POLLING = 0,
	SPI_MODE_INTERRUPT = 1
} spi_mode;



typedef struct {
	volatile spi_def *SPIx;
	uint8_t spinum; /* used for easy debugging */
	uint8_t priority;
	uint8_t prescaler;
	uint8_t cpol;
	uint8_t cpha;
	uint8_t dataform;
	spi_mode mode;

} spi_config;

/* Init section */
void spi_init(volatile spi_config *hspi);

/* Master section */

uint16_t spi_master_receive(volatile spi_config *hspi);

void  spi_master_transmit(volatile spi_config *hspi, uint16_t data);


/* Slave section */

uint16_t spi_slave_receive(volatile spi_config *hspi);

void spi_slave_transmit(volatile spi_config *hspi, uint16_t data);

#endif
