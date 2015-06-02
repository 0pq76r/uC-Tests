MCU=atmega2560
PROGRAMMER=wiring
PORT=-P/dev/ttyACM0
BAUD=-b115200

F_CPU=16000000L

TARGET=main

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
CFLAGS=-c -Wall -Werror -Os -DF_CPU=$(F_CPU)
LDFLAGS=-Wl,-u,vfprintf -lprintf_flt -lm

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
DEP=$(call rwildcard, src/, *.c *.h)
 
all: $(DEP) hex eeprom #program
 
hex: $(TARGET).hex
 
eeprom: $(TARGET)_eeprom.hex
 
$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $(TARGET).elf $(TARGET).hex
 
$(TARGET)_eeprom.hex: $(TARGET).elf
	avr-objcopy -O ihex -j .eeprom --change-section-lma .eeprom=1 $(TARGET).elf $(TARGET)_eeprom.hex
 
$(TARGET).elf: $(OBJECTS) $(DEP)
	avr-gcc -mmcu=$(MCU) $(LDFLAGS) $(OBJECTS) -o $(TARGET).elf
 
%.o : %.c $(DEP)
	avr-gcc -mmcu=$(MCU) $(CFLAGS) $< -o $@
  
size:
	avr-size --mcu=$(MCU) -C $(TARGET).elf
 
program: eeprom
	avrdude -F -p$(MCU) $(PORT) $(BAUD) -c$(PROGRAMMER) -Uflash:w:$(TARGET).hex:i
 
clean_tmp:
	rm -rf *.o
	rm -rf *.elf
 
clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.hex
