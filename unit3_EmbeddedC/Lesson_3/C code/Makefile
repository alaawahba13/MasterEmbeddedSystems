CC=arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS= -I
LIBs=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
projectName = lab2

all : lab2.bin


%.o : %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

lab2.elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

lab2.bin: lab2.elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all : 
	rm *.o *.elf *.bin

clean: 
	em *.o *.elf