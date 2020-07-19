MCU= cortex-m3
OBJCOPY= arm-none-eabi-objcopy
CC= arm-none-eabi-gcc
LD= arm-none-eabi-ld
DEF = -DSTM32F10X_MD
INCLUDE= -Ihal
INCLUDE+= -Ihal/CMSIS/core
INCLUDE+= -Isrc
CFLAGS= -mcpu=$(MCU) $(DEF) $(INCLUDE)
ASFLAGS= -mcpu=$(MCU)
LDFLAGS= -Tsrc/script.ld
TARGET= hello
BINDEST= bin/$(TARGET)

SOURCES = $(shell find . -name "*.c")
SOURCES += $(shell find . -name "*.s")
OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o obj/$(notdir $@) $<
	
%.o: %.s
	$(CC) $(ASFLAGS) -c -o obj/$(notdir $@) $<
    
all:	$(OBJECTS)
	$(LD) $(LDFLAGS) -o $(BINDEST).elf  $(wildcard obj/*.o)
	$(OBJCOPY) -O binary $(BINDEST).elf $(BINDEST).bin	

install:
	st-flash  write $(BINDEST).bin 0x08000000
	
clean: 
	@rm $(BINDEST).elf $(BINDEST).bin $(wildcard obj/*.o)
