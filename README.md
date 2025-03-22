# mcus-driver-lib

## Overview

This repository provides a modular, low-level driver library for multiple MCUs, focusing on bare-metal development and direct register manipulation. The library aims to offer lightweight, efficient, and reusable code for embedded systems, avoiding heavy HALs and unnecessary overhead.

## Features

1. Peripheral Drivers: UART, SPI, I2C, GPIO, TWI, PWM, WDT etc.

2. Multi-MCU Support: Check the list of supported MCUs below.

3. Modular Design: Each driver is implemented as a separate module, allowing easy integration and customization.

4. Minimal Dependencies: The library is designed to be lightweight and efficient, avoiding unnecessary overhead.

### Target MCUS

1. ATmega48A/48PA/88A/88PA/168A/168PA/328/328P

2. STM32: stm32f101xx/stm32f102xx/stm32f103xx (low- and medium-density)

3. rp2040: Planned

### Notice

#### Development Status

1. The ATmega drivers are the main focus, with plans to expand to the ATiny series.

2. STM32 development is paused while refining the ATmega implementation.

3. The RP2040 integration is planned but not yet started.

#### Caution

1. The library is under active development and may contain bugs.

2. **Contributions, bug reports, and suggestions are highly welcome.**
