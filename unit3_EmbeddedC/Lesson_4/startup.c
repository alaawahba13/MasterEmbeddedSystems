#include <stdint.h>
extern void main();
void Reset_Handler(void);
extern unsigned int _E_text;
extern unsigned int _E_data;
extern unsigned int _E_bss;
extern unsigned int _S_data;
extern unsigned int _S_bss;

void Default_Handler(void) {
	Reset_Handler();
}


void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_handler(void) __attribute__((weak, alias("Default_Handler")));
// reserve 1024 byte in the .bss section through unintialized array of 256 element
static unsigned long Stack_top[256];


 void  (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) ={

		 // define the stack pointer as the address of the last element in the array
	(void(*)())	 ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
    &H_Fault_handler

 };


void Reset_Handler(void) {
	// copy data from ROM to RAM
	unsigned int DATA_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char *p_scr = (unsigned char*)&_E_text ;
	unsigned char *p_dst = (unsigned char*)&_S_data ;
	for (int i = 0; i < DATA_size; i++) {
		*((unsigned char*) p_dst++) = *((unsigned char*) p_scr++);

	}
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	     p_dst = (unsigned char*)&_S_bss ;
		for (int i = 0; i < bss_size; i++) {
			*((unsigned char*) p_dst++) = ((unsigned char)0);
		}

	main();
}

