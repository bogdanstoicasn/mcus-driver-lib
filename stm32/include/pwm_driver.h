#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include "./util/stm32f103_def.h"
#include "./gpio_driver.h"

#define RCC_APB1ENR_TIM2EN    (1 << 0)
#define RCC_APB2ENR_IOPAEN    (1 << 2)

#define MAX_PRESCALER         65535
#define MAX_ARR               65535

#define TIM_CR1_CEN (1 << 0)

/* TIMx_CCMR1 definitions for Channel 1 (output compare) */
#define TIM_CCMR1_OC1M_POS    (4U)
#define TIM_CCMR1_OC1M_MSK    (0x7UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1PE       (1UL << 3U)
#define TIM_CCER_CC1E         (1 << 0)

/* TIMx_CCMR1 definitions for Channel 2 (output compare) */
#define TIM_CCMR1_OC2M_POS    (12U)
#define TIM_CCMR1_OC2M_MSK    (0x7UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2PE       (1UL << 11U)
#define TIM_CCER_CC2E         (1 << 4)

/* TIMx_CCMR2 definitions for Channel 3 (output compare) */
#define TIM_CCMR2_OC3M_POS    (4U)
#define TIM_CCMR2_OC3M_MSK    (0x7UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3PE       (1UL << 3U)
#define TIM_CCER_CC3E         (1 << 8)

/* TIMx_CCMR2 definitions for Channel 4 (output compare) */
#define TIM_CCMR2_OC4M_POS    (12U)
#define TIM_CCMR2_OC4M_MSK    (0x7UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4PE       (1UL << 11U)
#define TIM_CCER_CC4E         (1 << 12)

typedef enum {
	/* 6 and 7 */
	PWM_MODE_1 = 0b110,
	PWM_MODE_2 = 0b111
} pwm_mode;

void pwm_init(uint8_t pin, gpio_mode mode, pwm_mode pwmmode, uint16_t prescaler, uint16_t arr, uint16_t duty_cycle);

void pwm_set_duty(uint8_t pin, uint16_t duty_cycle);

void pwm_disable(uint8_t pin);

#endif
