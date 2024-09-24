## Makefile

Use **make + needed-util** to put the required files in the lib builder.
Example:
    
    1. make pwm adc => adds the pwm and adc to the lib

    2. make gpio    => adds the gpio to the lib

    3. make all     => adds everything to the lib

After each make use: **make lib** to create the ".a" file.

## Lib usage

Check the **.h** files for the functions name and usage.
