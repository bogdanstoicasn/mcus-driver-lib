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
} gpio_def;

typedef struct {
	volatile uint32_t cr;
	volatile uint32_t cfgr;
	volatile uint32_t cir;
	volatile uint32_t apb2rstr;
	volatile uint32_t apb1rstr;
	volatile uint32_t ahbenr;
	volatile uint32_t apb2enr;
	volatile uint32_t bdcr;
	volatile uint32_t csr;
} rcc_def;

typedef enum {
    // Input Modes (MODE = 00)
    GPIO_MODE_INPUT_ANALOG          = 0x0,  /* Analog input */
    GPIO_MODE_INPUT_FLOATING        = 0x4,  /* Floating input (reset state) */
    GPIO_MODE_INPUT_PU_PD           = 0x8,  /* Input with pull-up/pull-down */

    // Output Modes (MODE > 00)
    GPIO_MODE_OUTPUT_PP_10MHZ       = 0x1,  /* Output Push-Pull, 10 MHz */
    GPIO_MODE_OUTPUT_PP_2MHZ        = 0x2,  /* Output Push-Pull, 2 MHz */
    GPIO_MODE_OUTPUT_PP_50MHZ       = 0x3,  /* Output Push-Pull, 50 MHz */
    GPIO_MODE_OUTPUT_OD_10MHZ       = 0x5,  /* Output Open-Drain, 10 MHz */
    GPIO_MODE_OUTPUT_OD_2MHZ        = 0x6,  /* Output Open-Drain, 2 MHz */
    GPIO_MODE_OUTPUT_OD_50MHZ       = 0x7,  /* Output Open-Drain, 50 MHz */
    GPIO_MODE_AF_PP_10MHZ           = 0x9,  /* Alternate function Push-Pull, 10 MHz */
    GPIO_MODE_AF_PP_2MHZ            = 0xA,  /* Alternate function Push-Pull, 2 MHz */
    GPIO_MODE_AF_PP_50MHZ           = 0xB,  /* Alternate function Push-Pull, 50 MHz */
    GPIO_MODE_AF_OD_10MHZ           = 0xD,  /* Alternate function Open-Drain, 10 MHz */
    GPIO_MODE_AF_OD_2MHZ            = 0xE,  /* Alternate function Open-Drain, 2 MHz */
    GPIO_MODE_AF_OD_50MHZ           = 0xF   /* Alternate function Open-Drain, 50 MHz */
} gpio_mode;

#define GPIOA ((gpio_def *) GPIOA_BASE)
#define GPIOB ((gpio_def *) GPIOB_BASE)
#define GPIOC ((gpio_def *) GPIOC_BASE)
#define GPIOD ((gpio_def *) GPIOD_BASE)
#define GPIOE ((gpio_def *) GPIOE_BASE)
#define GPIOF ((gpio_def *) GPIOF_BASE)
#define GPIOG ((gpio_def *) GPIOG_BASE)

#define RCC   ((rcc_def *) RCC_BASE)

/* Function that starts the clock for gpio
 * 
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
 * @param *rcc - rcc register
*/
void gpio_setup(gpio_def *gpiox, rcc_def *rcc);

/* Function that configs the pin for different modes
 * 
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
 * @param pin    - pin
 * @param mode   - mode 
 * 
 * Caution: - use the setup function first
*/
void gpio_config_pin(gpio_def *gpiox, uint8_t pin, gpio_mode mode);

#endif
