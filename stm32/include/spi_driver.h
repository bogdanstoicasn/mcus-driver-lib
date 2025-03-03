#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "./util/stm32f103_def.h"

/* Master section */

void spi_master_init(void);

uint16_t spi_master_receive(void);

void  spi_master_transmit(uint16_t data);


/* Slave section */
void spi_slave_init(void);

uint16_t spi_slave_receive(void);

void spi_slave_transmit(uint16_t data);

#endif
