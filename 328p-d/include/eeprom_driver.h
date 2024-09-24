#ifndef EEPROM_DRIVER_H
#define EEPROM_DRIVER_H

#include "macros328p.h"

void eeprom_write(uint16_t addr, uint8_t data);

uint8_t eeprom_read(uint16_t addr);

#endif
