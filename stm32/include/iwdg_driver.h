#ifndef IWDG_DRIVER_H
#define IWDG_DRIVER_H

#include "./util/stm32f103_def.h"

#define IWDG_MAX_RELOAD 0x7FF
#define IWDG_MIN_RELOAD 0x000

/*
 * Macros used for write/reset
 */
#define IWDG_KEY_UNLOCK 0x5555
#define IWDG_KEY_RELOAD 0xAAAA
#define IWDG_KEY_START 0xCCCC

/*
 * Checking when updating the prescale/reload value
 * */
#define IWDG_SR_PVU (1 << 0)
#define IWDG_SR_RVU (1 << 1)

typedef enum {
	IWDG_PRESCALER_DIV_4 = 0,
	IWDG_PRESCALER_DIV_8 = 1,
	IWDG_PRESCALER_DIV_16 = 2,
	IWDG_PRESCALER_DIV_32 = 3,
	IWDG_PRESCALER_DIV_64 = 4,
	IWDG_PRESCALER_DIV_128 = 5,
	IWDG_PRESCALER_DIV_256 = 6
} iwdg_prescaler;

/*
 * @brief Enables Independent Watchdog with specified prescaler and reload values.
 *
 *  It starts the watchdog timer, which will reset the system if not refreshed
 *  before timeout.
 *
 *
 *  @param prescaler: Value used to divide the clock.
 *  @param reload: Value used to set the timeout period.
 *
 */
void iwdg_enable(iwdg_prescaler prescaler, uint16_t reload);

/*
 * @brief Changes the prescaler and reload values for the Independent Watchdog.
 *
 * Changes the prescale and reload while the IWDG is running.
 *
 *
 * @param new_prescaler: New prescaler value for IWDG.
 * @param new_reload: New reload value for IWDG.
 *
 */
void iwdg_change_settings(iwdg_prescaler new_prescaler, uint16_t new_reload);

/*
 * @brief Resets the Independent Watchdog timer.
 *
 * Writes an appropiate  value to the Key Register so that the counter will be
 * reloaded and start counting from it's initial values.
 *
 */
void iwdg_reset();


#endif
