CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS  = -mcpu=cortex-m33 -mthumb -O1 -g -Wall -ffreestanding
TARGET = ek_ra4c1_fw
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=$(TARGET).map -Wl,--gc-sections


all: $(TARGET).elf $(TARGET).bin
	mkdir -p build
	mv $(TARGET).* build/

CSOURCES = startup.c \
	   main.c

LINKER = linker.ld

$(TARGET).elf: $(CSOURCES) $(LINKER)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CSOURCES) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf build/
