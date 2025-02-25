CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m4 \
	   -mthumb \
	   -mlittle-endian \
	   -g -Wall \
	   --specs=nano.specs
LDFLAGS=-T startup.ld -nostdlib -Wl,-Map=output.map

all: main.o startup.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o main.elf main.o startup.o
	$(OBJCOPY) -O binary main.elf main.bin

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

startup.o: startup.c
	$(CC) $(CFLAGS) -c startup.c

dump: main.elf
	arm-none-eabi-objdump -h main.elf

flash: main.bin
	st-flash write main.bin 0x8000000

debug: main.elf
	arm-none-eabi-gdb main.elf

clean:
	rm -f *.o *.elf *.bin *.map