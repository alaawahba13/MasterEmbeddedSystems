CC=arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -mthumb -gdwarf-2
INCS= -I
LIBs=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
projectName = lab3_COORTEX_M4

all : $(projectName).bin


%.o : %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(projectName).elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(projectName).elf $(projectName).axf

$(projectName).bin: $(projectName).elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all : 
	rm *.o *.elf *.bin

clean: 
	rm *.o *.elf