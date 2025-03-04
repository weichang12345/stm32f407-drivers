CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m4 \
	   -mthumb \
	   -mlittle-endian \
	   -g -Wall \
	   --specs=nano.specs
LDFLAGS=-T ./startup.ld -nostdlib -Wl,-Map=output.map

CFLAGS+=-I./inc

STARTUP=./startup.c
STARTUP_OBJ=./startup.o

SRC=./main.c
SRC+=./src/gpio.c\
	 ./src/AHB1.c

OBJ_FILES=$(SRC:.c=.o)

EXECUTABLE=main.elf
BIN_IMAGE=main.bin


all: $(OBJ_FILES) $(STARTUP_OBJ) main.o gpio.o AHB1.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(STARTUP_OBJ) main.o gpio.o AHB1.o
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