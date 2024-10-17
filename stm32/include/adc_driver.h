#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H

#include "./util/stm32f103_def.h"

/* You must use the same ADC and PIN in all the funcions */

/* Uses only adc1 and 2
 * Uses only gpioa
 * All pins of gpioa 
 * Each conversion should be started manualy
 * Use this function 1 time
 */
void adc_init(adc_def *adc, uint8_t pin);

/* Start a conversion */
uint16_t adc_read(adc_def *adc, uint8_t pin);

/* Disable adc for less pwr usage */
void adc_disable(adc_def *adc);

#endif
