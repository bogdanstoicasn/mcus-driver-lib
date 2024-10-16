#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "./util/stm32f103_def.h"

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

/* Function that starts the clock for gpio
 * 
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
*/
void gpio_setup(gpio_def *gpiox);

/* Function that configs the pin for different modes
 * 
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
 * @param pin    - pin
 * @param mode   - mode 
 * 
 * Caution: - use the setup function first
*/
void gpio_config_pin(gpio_def *gpiox, uint8_t pin, gpio_mode mode);

/* Function that reads from a specific pin
 *
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
 * @param pin    - pin
 *
 * @return 1 or 0
 */
uint8_t gpio_read_pin(gpio_def *gpiox, uint8_t pin);
/* Function that toggles the state of a pin
 *
 * @param *gpiox - gpio register (ex: GPIOA, GPIOB, ...)
 * @param pin    - pin
 * */
void gpio_toggle_pin(gpio_def *gpiox, uint8_t pin);

#endif
