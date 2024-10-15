#ifndef BASE_32F103_H
#define BASE_32F103_H

#include <stdint.h>

/* Register boundary addresses */
#define TIM2_BASE           0x40000000
#define TIM3_BASE           0x40000400
#define TIM4_BASE           0x40000800
#define TIM5_BASE           0x40000C00
#define TIM6_BASE           0x40001000
#define TIM7_BASE           0x40001400
#define RTC_BASE            0x40002800
#define WWDG_BASE           0x40002C00
#define IWDG_BASE           0x40003000
#define SPI2_I2S_BASE       0x40003800
#define SPI3_I2S_BASE       0x40003C00
#define USART2_BASE         0x40004400
#define USART3_BASE         0x40004800
#define UART4_BASE          0x40004C00
#define UART5_BASE          0x40005000
#define I2C1_BASE           0x40005400
#define I2C2_BASE           0x40005800
#define USBDEV_FSREG_BASE   0x40005C00
#define USB_CAN_SHARED_BASE 0x40006000
#define BXCAN1_BASE         0x40006400
#define BXCAN2_BASE         0x40006800
#define BKP_BASE            0x40006C00
#define PWR_BASE            0x40007000
#define DAC_BASE            0x40007400
#define AFIO_BASE           0x40010000
#define EXTI_BASE           0x40010400
#define GPIOA_BASE          0x40010800
#define GPIOB_BASE          0x40010C00
#define GPIOC_BASE          0x40011000
#define GPIOD_BASE          0x40011400
#define GPIOE_BASE          0x40011800
#define GPIOF_BASE          0x40011C00
#define GPIOG_BASE          0x40012000
#define ADC1_BASE           0x40012400
#define ADC2_BASE           0x40012800
#define TIM1_BASE           0x40012C00
#define SPI1_BASE           0x40013000
#define TIM8_BASE           0x40013400
#define USART1_BASE         0x40013800
#define ADC3_BASE           0x40013C00
#define SDIO_BASE           0x40018000
#define DMA1_BASE           0x40020000
#define DMA2_BASE           0x40020400
#define RCC_BASE            0x40021000
#define FLASH_MEM_INT_BASE  0x40022000
#define CRC_BASE            0x40023000
#define ETHERNET_BASE       0x40028000
#define USB_OTG_FS_BASE     0x50000000



#endif
