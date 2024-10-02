#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "macros32f103.h"

typedef struct {
	volatile uint32_t crl;
	volatile uint32_t crh;
	volatile uint32_t idr;
	volatile uint32_t odr;
	volatile uint32_t bsrr;
	volatile uint32_t brr;
	volatile uint32_t lckr;
}gpio_def;

#define GPIOA ((gpio_def *) GPIOA_BASE)
#define GPIOB ((gpio_def *) GPIOB_BASE)
#define GPIOC ((gpio_def *) GPIOC_BASE)
#define GPIOD ((gpio_def *) GPIOD_BASE)
#define GPIOE ((gpio_def *) GPIOE_BASE)
#define GPIOF ((gpio_def *) GPIOF_BASE)
#define GPIOG ((gpio_def *) GPIOG_BASE)

#endif
