#include <util/delay.h>
#include "./include/led_driver.h"

int main()
{
	led_setup();

	while(1) {
		led_toggle();
		_delay_ms(2000);
	}
	return 0;
}
