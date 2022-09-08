#include "uart.h"
unsigned char string_buffer[100] = "Learn-in-depth: Alaa Wahba";
void main(void){
	
	 uart_send_string(string_buffer);
}