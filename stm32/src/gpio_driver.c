#include "../include/gpio_driver.h"

void gpio_setup(gpio_def *gpiox)
{
	/* Start the clock for the gpio 
	 * If not matching pointer, set gpioa
	 */
	if (gpiox == GPIOA)
		RCC->apb2enr |= (1 << 2);
	else if (gpiox == GPIOB)
		RCC->apb2enr |= (1 << 3);
	else if (gpiox == GPIOC)
		RCC->apb2enr |= (1 << 4);
	else if (gpiox == GPIOD)
		RCC->apb2enr |= (1 << 5);
	else if (gpiox == GPIOE)
		RCC->apb2enr |= (1 << 6);
	else if (gpiox == GPIOF)
		RCC->apb2enr |= (1 << 7);
	else if (gpiox == GPIOG)
		RCC->apb2enr |= (1 << 8);
	else
		RCC->apb2enr |= (1 << 2);

}

/* TODO: Add pull-up/down variable and functionality*/
void gpio_config_pin(gpio_def *gpiox, uint8_t pin, gpio_mode mode) {
    if (pin < 8) {
        // Configure pin in CRL register (pins 0-7)
        gpiox->crl &= ~(0xF << (pin * 4));  // Clear the 4 bits for the pin
        gpiox->crl |= (mode << (pin * 4));  // Set mode and configuration
    } else {
        // Configure pin in CRH register (pins 8-15)
        pin -= 8;
        gpiox->crh &= ~(0xF << (pin * 4));  // Clear the 4 bits for the pin
        gpiox->crh |= (mode << (pin * 4));  // Set mode and configuration
    }
}

uint8_t gpio_read_pin(gpio_def *gpiox, uint8_t pin)
{
	return (gpiox->idr & (1 << pin)) ? 1 : 0;
}

void gpio_toggle_pin(gpio_def *gpiox, uint8_t pin)
{
	gpiox->odr ^= (1 << pin);
}


