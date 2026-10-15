ENTRY (Reset_Handler)

MEMORY
{
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x8000
        RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x18000
}

_min_heap_size  = 0x1000; /* 4KB */
_min_stack_size = 0x800;  /* 2KB */

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

	.heap (NOLOAD) : ALIGN(8)
	{
		. = ALIGN(8);
		PROVIDE(end = .);
		PROVIDE(_end = .);
		_sheap = .;
		. = . + _min_heap_size;
		. = ALIGN(8);
		_eheap = .;
	} > RAM

	.stack (ORIGIN(RAM) + LENGTH(RAM) - _min_stack_size) (NOLOAD) : ALIGN(8)
	{
		_sstack = .;
		. = . + _min_stack_size;
		_estack = .;
	} > RAM
}
