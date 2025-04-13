CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m4 \
	   -mthumb \
	   -mlittle-endian \
	   -g -Wall \
	   --specs=nano.specs
LDFLAGS=-T ./startup.ld -nostdlib -Wl,-Map=output.map

# Include header files
CFLAGS+=-I./
CFLAGS+=-I./drivers/inc
CFLAGS+=-I./interrupt
CFLAGS+=-I./Cortex-M4/inc
CFLAGS+=-I./morse_code

# Startup file
STARTUP=./startup.c
STARTUP_OBJ=./startup.o

# Add driver files
SRC=./main.c
SRC+=./drivers/src/gpio.c \
	 ./drivers/src/rcc.c \
	 ./drivers/src/syscfg.c \
	 ./drivers/src/exti.c \
	 ./drivers/src/usart.c
SRC+=./interrupt/interrupt.c
SRC+=./morse_code/morse.c

# Add core peripherals
SRC+=./Cortex-M4/src/nvic.c

# Modify object files path
OBJ_FILES:=$(SRC:.c=.o)
OBJ_FILES:=$(patsubst ./drivers/src/%, %, $(OBJ_FILES))
OBJ_FILES:=$(patsubst ./interrupt/%, %, $(OBJ_FILES))
OBJ_FILES:=$(patsubst ./Cortex-M4/src/%, %, $(OBJ_FILES))
OBJ_FILES:=$(patsubst ./morse_code/%, %, $(OBJ_FILES))

EXECUTABLE=main.elf
BIN_IMAGE=main.bin


all:$(STARTUP_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(STARTUP_OBJ) $(OBJ_FILES)
	$(OBJCOPY) -O binary $(EXECUTABLE) $(BIN_IMAGE)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $^

$(OBJ_FILES): $(SRC)
	$(CC) $(CFLAGS) -c $^

dump: main.elf
	arm-none-eabi-objdump -h main.elf

flash: main.bin
	st-flash write main.bin 0x8000000

debug: 
	arm-none-eabi-gdb -q -x ./.gdbinit
	
monitor:
	openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg

clean:
	rm -f *.o *.elf *.bin *.map