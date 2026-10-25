CC	= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
INC_DIR = inc
CFLAGS  = -mcpu=cortex-m33 -mthumb -O0 -g -Wall -ffreestanding -I$(INC_DIR)
TARGET 	= ek_ra4c1_fw
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=$(TARGET).map -Wl,--gc-sections


all: $(TARGET).elf $(TARGET).bin
	mkdir -p build
	mv $(TARGET).* build/

CSOURCES = 	src/startup.c \
			src/nvic.c	\
	   		src/main.c	\
	   		src/init.c	\
	   		src/icu.c

LINKER = linker.ld

$(TARGET).elf: $(CSOURCES) $(LINKER)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CSOURCES) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf build/
