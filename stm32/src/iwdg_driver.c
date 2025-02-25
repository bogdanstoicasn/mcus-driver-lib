#include "../include/iwdg_driver.h"

void iwdg_enable(iwdg_prescaler prescaler, uint16_t reload)
{
	if(reload > IWDG_MAX_RELOAD)
		reload = IWDG_MAX_RELOAD;

	IWDG->kr = IWDG_KEY_UNLOCK;

	IWDG->pr = prescaler;
	while (IWDG->sr & IWDG_SR_PVU);

	IWDG->rlr = reload;
	while (IWDG->sr & IWDG_SR_RVU);

	IWDG->kr = IWDG_KEY_START;

	IWDG->kr = IWDG_KEY_RELOAD;
}

void iwdg_reset()
{
	IWDG->kr = IWDG_KEY_RELOAD;
}

void iwdg_change_settings(iwdg_prescaler new_prescaler, uint16_t new_reload)
{
	IWDG->kr = IWDG_KEY_RELOAD;

	if (new_reload > IWDG_MAX_RELOAD)
		new_reload = IWDG_MAX_RELOAD;

	IWDG->kr = IWDG_KEY_UNLOCK;

	IWDG->pr = new_prescaler;
	while (IWDG->sr & IWDG_SR_PVU);

	IWDG->rlr = new_reload;
	while(IWDG->sr & IWDG_SR_RVU);

	IWDG->kr = IWDG_KEY_RELOAD;
}
