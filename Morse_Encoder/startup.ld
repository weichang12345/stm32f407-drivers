ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
    SRAM (rwx) : ORIGIN =  0x20000000, LENGTH = 128K
}

SECTIONS
{
    .text : 
    {
        . = ALIGN(4);

        KEEP(*(.IVT))
        *(.text) 
        *(.rodata)

        . = ALIGN(4);
        _etext = .;
    } > FLASH

    .data : 
    {
        _sidata = LOADADDR(.data);
        . = ALIGN(4);
        _sdata = .;

        *(.data)

        . = ALIGN(4);
        _edata = .;
    } > SRAM AT> FLASH

    .bss : 
    {
        . = ALIGN(4);
        _sbss = .;

        *(.bss)

        . = ALIGN(4);
        _ebss = .;
    } > SRAM
}