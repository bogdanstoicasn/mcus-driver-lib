#ifndef DEF_32f103_H
#define DEF_32f103_H

#include "stm32f103_base.h"

#define BITBAND(addr, bit)(*(volatile uint32_t *)(0x42000000 + ((uint32_t)(addr) - 0x40000000) * 32 + (bit * 4)))

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
	volatile uint32_t apb1rstr;
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

/* IWDG register components */
typedef struct {
	volatile uint32_t kr;
	volatile uint32_t pr;
	volatile uint32_t rlr;
	volatile uint32_t sr;
} iwdg_def;

/* WWDG register components */
typedef struct {
	volatile uint32_t cr;
	volatile uint32_t cfr;
	volatile uint32_t sr;
} wwdg_def;

/* TIM2/3/4 register components */
typedef struct {
	volatile uint32_t cr1;
	volatile uint32_t cr2;
	volatile uint32_t smcr;
	volatile uint32_t dier;
	volatile uint32_t sr;
	volatile uint32_t egr;
	volatile uint32_t ccmr1;
	volatile uint32_t ccmr2;
	volatile uint32_t ccer;
	volatile uint32_t cnt;
	volatile uint32_t psc;
	volatile uint32_t arr;
	volatile uint32_t RESERVED0;
	volatile uint32_t ccr1;
	volatile uint32_t ccr2;
	volatile uint32_t ccr3;
	volatile uint32_t ccr4;
	volatile uint32_t RESERVED1;
	volatile uint32_t dcr;
	volatile uint32_t dmar;
} timgen_def;

typedef struct {
	volatile uint32_t cr1;
	volatile uint32_t cr2;
	volatile uint32_t sr;
	volatile uint32_t dr;
	volatile uint32_t crcpr;
	volatile uint32_t txcrcr;
	volatile uint32_t i2scfgr;
	volatile uint32_t i2spr;
} spi_def;

#define GPIOA ((volatile gpio_def *) GPIOA_BASE)
#define GPIOB ((volatile gpio_def *) GPIOB_BASE)
#define GPIOC ((volatile gpio_def *) GPIOC_BASE)
#define GPIOD ((volatile gpio_def *) GPIOD_BASE)
#define GPIOE ((volatile gpio_def *) GPIOE_BASE)
#define GPIOF ((volatile gpio_def *) GPIOF_BASE)
#define GPIOG ((volatile gpio_def *) GPIOG_BASE)

#define RCC   ((volatile rcc_def *) RCC_BASE)

#define USART1 ((volatile usart_def *) USART1_BASE)
#define USART2 ((volatile usart_def *) USART2_BASE)
#define USART3 ((volatile usart_def *) USART3_BASE)

#define ADC1 ((volatile adc_def *) ADC1_BASE)
#define ADC2 ((volatile adc_def *) ADC2_BASE)

#define IWDG ((volatile iwdg_def *) IWDG_BASE)
#define WWDG ((volatile wwdg_def *) WWDG_BASE)

#define TIM2 ((volatile timgen_def *) TIM2_BASE)
#define TIM3 ((volatile timgen_def *) TIM3_BASE)
#define TIM4 ((volatile timgen_def *) TIM4_BASE)

#define SPI1 ((volatile spi_def *) SPI1_BASE)
#define SPI2_I2S ((volatile spi_def *) SPI2_I2S_BASE)
#define SPI3_I2S ((volatile spi_def *) SPI3_I2S_BASE)

#endif
