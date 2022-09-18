#include <stdint.h>
extern void main();
void Reset_Handler(void);
extern unsigned int _E_text;
extern unsigned int _E_data;
extern unsigned int _E_bss;
extern unsigned int _S_data;
extern unsigned int _S_bss;
extern unsigned int Stack_top;

void Default_Handler(void) {
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
;
void H_Fault_handler(void) __attribute__((weak, alias("Default_Handler")));
;
void Bus_Handler(void) __attribute__((weak, alias("Default_Handler")));
;

uint32_t vectors[] __attribute__((section(".vectors"))) = {

(uint32_t) &Stack_top, (uint32_t) &Reset_Handler, (uint32_t) &NMI_Handler,
		(uint32_t) &H_Fault_handler, (uint32_t) &Bus_Handler

};
void Reset_Handler(void) {
	// copy data from ROM to RAM
	unsigned int DATA_size = (unsigned int*) &_E_data - (unsigned int*) &_S_data;
	unsigned char *p_scr = (unsigned char*) &_E_text ;
	unsigned char *p_dst = (unsigned char*) &_S_data ;
	for (int i = 0; i < DATA_size; i++) {
		*((unsigned char*) p_dst++) = *((unsigned char*) p_scr++);

	}
	unsigned int bss_size = (unsigned int*) &_E_bss - (unsigned int*) &_S_bss;
	     p_dst = (unsigned char*) &_S_bss ;
		for (int i = 0; i < bss_size; i++) {
			*((unsigned char*) p_dst++) = ((unsigned char)0);
		}

	main();
}
