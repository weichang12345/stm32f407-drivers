add-auto-load-safe-path /home/winstonchang/workspace/stm32f407-projects/Morse_Encoder_Decoder/.gdbinit
target extended-remote localhost:3333
monitor flash write_image erase main.elf
file main.elf
