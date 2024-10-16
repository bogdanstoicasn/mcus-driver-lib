# Compiler and Flags
CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -Werror -Wextra -g

LDFLAGS = -Tstm32f103c8.ld

AR = ar

ARFLAGS = rcs

#Library and sources
LIBRARY = stm32f103c8-d.a

GPIO_SRC = src/gpio_driver.c
GPIO_OBJ = $(GPIO_SRC:.c=.o)

USART_SRC = src/usart_driver.c
USART_OBJ = $(USART_SRC:.c=.o)

#Files to keep track of lib objects
LIB_OBJS_FILE = lib_objs.txt

#Main app
MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

#Rule to add modules to the lib
gpio: $(GPIO_OBJ)
	echo $(GPIO_OBJ) >> $(LIB_OBJS_FILE)
	@echo "GPIO driver added to the library!"

usart: $(USART_OBJ)
	echo $(USART_OBJ) >> $(LIB_OBJS_FILE)
	@echo "USART driver added to the library!"

#Rule to create the lib
lib: $(LIB_OBJS_FILE)
	@echo "Creating library with objects: $(shell cat $(LIB_OBJS_FILE))"
	$(AR) $(ARFLAGS) $(LIBRARY) $(shell cat $(LIB_OBJS_FILE))
	@echo "Library created: $(LIBRARY)"

#Rule all
all: gpio usart
	@echo "All drivers added to the library!"

#Rule to build main and link lib
run: all $(MAIN_OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) -o main.elf $(MAIN_SRC) $(LIBRARY) $(LDFLAGS)

#Rule to build objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Rule to clean
clean:
	rm -f $(GPIO_OBJ) $(USART_OBJ) $(MAIN_OBJ) $(LIBRARY) $(LIB_OBJS_FILE) main.elf

#Phony targets
.PHONY: all run clean lib gpio usart


