#ifndef WWDG_DRIVER_H
#define WWDG_DRIVER_H

#include "./util/stm32f103_def.h"

#define RCC_APB1ENR_WWDG_EN (1 << 11) /* Must enable wwdg clock source from RCC*/

#define WWDG_CR_T_MASK (0x7F)
#define WWDG_CR_WDGA (1 << 7) /* 0x40 */

#define WWDG_CFR_W_MASK WWDG_CR_T_MASK
#define WWDG_CFR_EWI (1 << 9)
#define WWDG_CFR_EWIF (1 << 0)


/* Right now unsafe */

void wwdg_init(uint8_t prescaler, uint8_t window, uint8_t counter);

void wwdg_reset(uint8_t counter);

void wwdg_earlywakeup();

void wwdg_earlywakeup_clear();

#endif 
