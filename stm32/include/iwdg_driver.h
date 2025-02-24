#ifndef IWDG_DRIVER_H
#define IWDG_DRIVER_H

#include "./util/stm32f103_def.h"

typedef enum {
	IWDG_PRESCALER_DIV_4 = 0,
	IWDG_PRESCALER_DIV_8 = 1,
	IWDG_PRESCALER_DIV_16 = 2,
	IWDG_PRESCALER_DIV_32 = 3,
	IWDG_PRESCALER_DIV_64 = 4,
	IWDG_PRESCALER_DIV_128 = 5,
	IWDG_PRESCALER_DIV_256 = 6
} iwdg_prescaler;

void iwdg_enable(iwdg_prescaler prescaler, uint16_t reload);

void iwdg_reset();

void iwdg_disable();

#endif
