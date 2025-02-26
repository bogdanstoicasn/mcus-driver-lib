#include "../include/wwdg_driver.h"

void wwdg_init(uint8_t prescaler, uint8_t window, uint8_t counter)
{
	WWDG->cfr = ((prescaler & 0x03) << 7) | (window & WWDG_CR_T_MASK);
	WWDG->cr = (counter & WWDG_CR_T_MASK) | WWDG_CR_WDGA; /* Enable WWDG */
}

void wwdg_reset(uint8_t counter)
{
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
