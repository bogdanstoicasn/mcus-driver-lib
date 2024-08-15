#ifndef TWI_DRIVER_H
#define TWI_DRIVER_H

#include "macros328p.h"

#define STATUS_SUCCESS 0
#define STATUS_FAILURE 1

#define TWI_READ        1
#define TWI_WRITE       0

#define TWI_READ_ACK    1
#define TWI_READ_NACK   0

#define TWI_SCL_PIN     PORTC5
#define TWI_SDA_PIN     PORTC4

#define TWI_SLA_W(addr) ((addr << 1) | TWI_WRITE)
#define TWI_SLA_R(addr) ((addr << 1) | TWI_READ)

#define TWI_STATUS      (TWSR & ((1 << TWS3) | (1 << TWS4) | (1 << TWS5) | (1 << TWS6) | (1 << TWS7))) 

typedef enum {
	twi_freq_100k,
	twi_freq_250k,
	twi_freq_400k
} twi_freq_mode;

#endif
