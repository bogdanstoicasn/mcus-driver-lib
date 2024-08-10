#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "macros328p.h"

/*                      <ARDUINO UNO>
 * Here we are mapping the <Arduino Uno> pins to the atmega328p:
 *
 * D2 - D13 = digital pins
 * D1, D0 = serial pins
 * D19, D18 = analog reference pins
 * A0 - A5 = analog pins
 *
 * The '_' represents the aditional functionality the pin can have.
 * (PWM, I2C etc)
 */
#define D19_SCL PORTC5
#define D18_SDA PORTC4
#define D13     PORTB5
#define D12     PORTB4
#define D11_PWM PORTB3
#define D10_PWM PORTB2
#define D9_PWM  PORTB1
#define D8      PORTB0
#define D7      PORTD7
#define D6_PWM  PORTD6
#define D5_PWM  PORTD5
#define D4      PORTD4
#define D3_PWM  PORTD3
#define D2      PORTD2
#define D1_TX   PORTD1
#define D0_RX   PORTD0

#define A0      PORTC0
#define A1      PORTC1
#define A2      PORTC2
#define A3      PORTC3
#define A4      PORTC4
#define A5      PORTC5



#define TX_LED  PORTD5
#define RX_LED  PORTD4
#define RESET   PORTC6 
#define LED_BUILTIN PORTB5

void led_setup();
void led_toggle();

#endif
