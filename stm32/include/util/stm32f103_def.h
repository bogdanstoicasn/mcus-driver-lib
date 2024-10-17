#ifndef DEF_32f103_H
#define DEF_32f103_H

#include "stm32f103_base.h"

/* GPIO register components */
typedef struct {
	volatile uint32_t crl;
	volatile uint32_t crh;
	volatile uint32_t idr;
	volatile uint32_t odr;
	volatile uint32_t bsrr;
	volatile uint32_t brr;
	volatile uint32_t lckr;
} gpio_def;

/* RCC register components */
typedef struct {
	volatile uint32_t cr;
	volatile uint32_t cfgr;
	volatile uint32_t cir;
	volatile uint32_t apb2rstr;
	volatile uint32_t abp1rstr;
	volatile uint32_t ahbenr;
	volatile uint32_t apb2enr;
	volatile uint32_t apb1enr;
	volatile uint32_t bdcr;
	volatile uint32_t csr;
} rcc_def;

/* USART1 register components */
typedef struct {
	volatile uint32_t sr;
	volatile uint32_t dr;
	volatile uint32_t brr;
	volatile uint32_t cr1;
	volatile uint32_t cr2;
	volatile uint32_t cr3;
	volatile uint32_t gtpr;
} usart_def; 

/* ADC register components*/
typedef struct {
	volatile uint32_t sr;
	volatile uint32_t cr1;
	volatile uint32_t cr2;
	volatile uint32_t smpr1;
	volatile uint32_t smpr2;
	volatile uint32_t jofr1;
	volatile uint32_t jofr2;
	volatile uint32_t jofr3;
	volatile uint32_t jofr4;
	volatile uint32_t htr;
	volatile uint32_t ltr;
	volatile uint32_t sqr1;
	volatile uint32_t sqr2;
	volatile uint32_t sqr3;
	volatile uint32_t jsqr;
	volatile uint32_t jdr1;
	volatile uint32_t jdr2;
	volatile uint32_t jdr3;
	volatile uint32_t jdr4;
	volatile uint32_t dr;
} adc_def;


#define GPIOA ((gpio_def *) GPIOA_BASE)
#define GPIOB ((gpio_def *) GPIOB_BASE)
#define GPIOC ((gpio_def *) GPIOC_BASE)
#define GPIOD ((gpio_def *) GPIOD_BASE)
#define GPIOE ((gpio_def *) GPIOE_BASE)
#define GPIOF ((gpio_def *) GPIOF_BASE)
#define GPIOG ((gpio_def *) GPIOG_BASE)

#define RCC   ((rcc_def *) RCC_BASE)

#define USART1 ((usart_def *) USART1_BASE)
#define USART2 ((usart_def *) USART2_BASE)
#define USART3 ((usart_def *) USART3_BASE)

#define ADC1 ((adc_def *) ADC1_BASE)
#define ADC2 ((adc_def *) ADC2_BASE)

#endif
