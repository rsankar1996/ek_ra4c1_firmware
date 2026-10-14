ENTRY (Reset_Handler)

MEMORY
{
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x8000
        RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x18000
}

_estack = ORIGIN(RAM) + LENGTH (RAM);

SECTIONS
{
        .text : ALIGN(4)
        {
                KEEP(*(.vectors*))
                *(.text*)
        } > FLASH
        
        .rodata : ALIGN(4)
        {
                *(.rodata*)
        } > FLASH
        
        _sidata = LOADADDR(.data);

        .data : ALIGN(4)
        {
                _sdata = .;
                *(.data*)
                . = ALIGN(4);
                _edata = .;
        } > RAM AT> FLASH

        .bss : ALIGN(4)
        {
                _sbss = .;
                *(.bss*)
                *(COMMON)
                . = ALIGN(4);
                _ebss = .;
        } > RAM
}
