#include "../include/pwm_driver.h"


void pwm_init(uint8_t pin, gpio_mode mode, pwm_mode  pwmmode,  uint16_t prescaler, uint16_t arr, uint16_t duty_cycle)
{
	if (pin > 3)
		pin = 0;

	if (mode != GPIO_MODE_AF_PP_2MHZ && mode != GPIO_MODE_AF_PP_10MHZ && mode != GPIO_MODE_AF_PP_50MHZ)
		mode = GPIO_MODE_AF_PP_50MHZ;

	RCC->apb1enr |= RCC_APB1ENR_TIM2EN;
	RCC->apb2enr |= RCC_APB2ENR_IOPAEN;

	GPIOA->crl &= ~(0xF << (pin * 4));
	GPIOA->crl |= (mode << (pin * 4));

	TIM2->psc = prescaler - 1; /* The lib handles the "-1" for ease of use */
	TIM2->arr = arr - 1;
	
	/* TIMx->>ccmrx: configure channel in chosen pwm mode*/
	switch (pin) {
	case 0: {
		TIM2->ccr1 = duty_cycle;

		TIM2->ccmr1 &= ~(0x7 << TIM_CCMR1_OC1M_POS);
		TIM2->ccmr1 |= ((pwmmode & 0x7) << TIM_CCMR1_OC1M_POS) | TIM_CCMR1_OC1PE;

		TIM2->ccer |= TIM_CCER_CC1E;
		break;
	}
	case 1: {
		TIM2->ccr2 = duty_cycle;
		
		TIM2->ccmr1 &= ~(0x7 << TIM_CCMR1_OC2M_POS);
		TIM2->ccmr1 |= ((pwmmode & 0x7) << TIM_CCMR1_OC2M_POS) | TIM_CCMR1_OC2PE;

		TIM2->ccer |= TIM_CCER_CC2E;
		break;
	}
	case 2: {
		TIM2->ccr3 = duty_cycle;
		
		TIM2->ccmr2 &= ~(0x7 << TIM_CCMR2_OC3M_POS);
		TIM2->ccmr2 |= ((pwmmode & 0x7) << TIM_CCMR2_OC3M_POS) | TIM_CCMR2_OC3PE;
		
		TIM2->ccer |= TIM_CCER_CC3E;
		break;
	}
	case 3: {
		TIM2->ccr4 = duty_cycle;

		TIM2->ccmr2 &= ~(0x7 << TIM_CCMR2_OC4M_POS);
		TIM2->ccmr2 |= ((pwmmode & 0x7) << TIM_CCMR2_OC4M_POS) | TIM_CCMR2_OC4PE;

		TIM2->ccer |= TIM_CCER_CC4E;
		break;
	}
	default:
			break;
	}

	TIM2->cr1 |= TIM_CR1_CEN;
}

void pwm_set_duty(uint8_t pin, uint16_t duty_cycle)
{
	if (pin > 3)
		pin = 0;

	switch (pin) {
	case 0:
		TIM2->ccr1 = duty_cycle;
		break;
	case 1:
		TIM2->ccr2 = duty_cycle;
		break;
	case 2:
		TIM2->ccr3 = duty_cycle;
		break;
	case 3:
		TIM2->ccr4 = duty_cycle;
		break;
	default:
		break;
	}
}

void pwm_disable(uint8_t pin)
{
	if (pin > 3)
		pin = 0;

	switch (pin) {
	case 0:
		TIM2->ccer &= ~TIM_CCER_CC1E;
		break;
	case 1:
		TIM2->ccer &= ~TIM_CCER_CC2E;
		break;
	case 2:
		TIM2->ccer &= ~TIM_CCER_CC3E;
		break;
	case 3:
		TIM2->ccer &= ~TIM_CCER_CC4E;
		break;
	default:
		break;
	}
}
	
