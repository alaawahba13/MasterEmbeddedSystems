/*
 * USART.c
 *
 *  Created on: 13 Feb 2023
 *      Author: Alaa Wahba
 */

#include "USART.h"
#define Default_Stop 		'\r'
static int flag=1;
static uint8 *TX_str;
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
	for (uint8 i = 0; i < str[i]; i++)
		USART_send(str[i]);

	USART_send(Default_Stop);
}

void USART_recieveString(uint8 *Buff) {

	uint8 i = 0;
	Buff[i] = USART_recieve();
	while (Buff[i] != Default_Stop) {
		i++;
		Buff[i] = USART_recieve();
	}
	Buff[i] = '\0';
}

uint8 USART_recievePeriodicData(uint8 *data){
	if(GET(UCSRA, RXC)){
		*data = UDR;
		return 1; 	//As an indication that there's sent data
	}
	return 0 ; 			// When no data is sent
}

//Interrupt
void USART_sendNoBlock(uint8 data){
	UDR =data;
}
uint8 USART_recieveNoBlock(){
	return UDR;
}
void USART_TX_interrupt_Enable(){
	SET(UCSRB,TXCIE);
}
void USART_TX_interrupt_Disable(){
	CLEAR(UCSRB,TXCIE);
}

void USART_RX_interrupt_Enable(){
	SET(UCSRB,RXCIE);
}
void USART_RX_interrupt_Disable(){
	CLEAR(UCSRB,RXCIE);

}
void USART_send_string_Asynch(uint8 *str){
	if(flag == 1){
		USART_TX_interrupt_Enable();
		USART_sendNoBlock(str[0]);
		TX_str = str;
		flag =0;
	}
}

ISR(USART_TXC_vect){
		static uint8 i =1;
		if(TX_str[i] != 0){
			USART_sendNoBlock(TX_str[i]);
			i++;
		}
		else{
			i =1 ;
			flag = 1; // Flag is set to one when transmit is complete.

		}
}
