/*
 * USART.c
 *
 *  Created on: 13 Feb 2023
 *      Author: Alaa Wahba
 */

#include "USART.h"

void USART_init(void) {
	/*   Baud rate   */
	// For 9600 bps
	UBRRL = 51;
	CLEAR(UCSRA, U2X);

	/*  FRAME 	  */
	//This bit selects  Asynchronous
	CLEAR(UCSRC, UMSEL);
	//These bits enable and set type of parity generation (No parity )
	CLEAR(UCSRC, UPM0);
	CLEAR(UCSRC, UPM1);
	//This bit selects the number of Stop Bits to be inserted by the Transmitter (1 bit)
	CLEAR(UCSRC, USBS);
	// sets the number of data bits (8 bits by default)
	SET(UCSRC, UCSZ1);
	SET(UCSRC, UCSZ0);
	CLEAR(UCSRB, UCSZ2);
	/*   Enable  */
	SET(UCSRB, RXEN);	//Writing this bit to one enables The USART Receiver.
	SET(UCSRB, TXEN);	//Writing this bit to one enables The USART Transmitter.

}

void USART_send(uint8 data) {
	//The transmit buffer can only be written when the UDRE Flag in the UCSRA Register is set.
	while (!GET(UCSRA, UDRE));
	UDR = data;

}
uint8 USART_recieve() {
	/*
	 * This flag bit is set when there are unread data in the receive buffer
	 * and cleared when the receive buffer is empty
	 */
	while (!GET(UCSRA, RXC));
	return UDR;

}

void USART_sendNumber(uint32 data) {
	/*uint8 *p = &data;
	 USART_send(p[0]);
	 USART_send(p[1]);
	 USART_send(p[2]);
	 USART_send(p[3]);*/
	char str[7];

	sprintf(str, "%d", data);  // Adjust the formatting to your liking.

	USART_sendString(str);

}
uint32 USART_recieveNumber() {
	/*uint32 num;
	 uint8 *p =&num;
	 p[0] = USART_recieve();
	 p[1] = USART_recieve();
	 p[2] = USART_recieve();
	 p[3] = USART_recieve();
	 return  num;*/
	return 0;
}
void USART_sendString(uint8 *str) {
	while(*str != '\0'){
			USART_send(*str++);
		}

}
char arr[50];
char* USART_recieveString() {
	char* str = arr;

			while(1){
				*(str) = USART_recieve();
				if(*(str) == ' '){
					break;
				}
				str++;
			}
			return arr;
}

