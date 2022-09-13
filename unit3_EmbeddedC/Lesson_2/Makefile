CC=arm-none-eabi-
CFLAGS = -g -mcpu=arm926ej-s
INCS= -I
LIBs=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all : lab1.bin


%.o : %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

lab1.elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

lab1.bin: lab1.elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all : 
	rm *.o *.elf *.bin

clean: 
	em *.o *.elf