#include "../include/wwdg_driver.h"

void wwdg_init(uint8_t prescaler, uint8_t window, uint8_t counter)
{
	/* clock source */
	RCC->apb1enr |= RCC_APB1ENR_WWDG_EN;

	/* window and prescaler */
	WWDG->cfr = ((prescaler & 0x03) << 7) | (window & WWDG_CFR_W_MASK);

	/* counter and wwdg enable */
	WWDG->cr = (counter & WWDG_CR_T_MASK) | WWDG_CR_WDGA;
}

void wwdg_reset(uint8_t counter)
{
	/* counter always over 0x42 for safety */
	counter = (counter < 0x42) ? 0x42 : counter;
	WWDG->cr = (WWDG->cr & ~WWDG_CR_T_MASK) | (counter & WWDG_CR_T_MASK);
}

void wwdg_earlywakeup()
{
	WWDG->cfr |= WWDG_CFR_EWI;
}

void wwdg__earlywakeup_clear()
{
	WWDG->sr &= ~WWDG_CFR_EWIF;
}
