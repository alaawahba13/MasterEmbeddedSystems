/*
 * Timer.c
 *
 *  Created on: 2 Aug 2023
 *      Author:  Alaa Wahba
 */
#include "Timer.h"

void (*G_CallBack_OVF)(void);
void (*G_CallBack_CTC)(void);
uint8 OVF_Number=0;

void Timer0_init(TIMER0_PinConfig_t *pinConfig){
	if(NULL != pinConfig){
	TCCR0 |= pinConfig->mode;
	TCCR0 |= pinConfig->clk;
	TIMSK |=pinConfig->OCIE;
	TIMSK |= pinConfig->TOIE;
	TCCR0 |= pinConfig->OC0;
	}

}
void Timer0_Stop(){
	TCCR0 = NONE;
}

uint8 Timer0_GetCompareValue(){
	return OCR0;
}
void Timer0_SetCompareValue(uint8 value){
	OCR0 = value;
}

uint8 Timer0_GetCountValue(){
	return TCNT0;
}
void Timer0_SetCountValue(uint8 value){
	TCNT0 = value;
}

uint8 Timer0_GetOverflowValue(){
	return OVF_Number ;
}
void Timer0_SetOverflowValue(uint8 value){
	OVF_Number = value;
}

void Timer0_CallBack_CTC(void(*ptr)(void) ){
	G_CallBack_CTC = ptr;
}
void Timer0_CallBack_Overflow(void(*ptr)(void) ){
	G_CallBack_OVF = ptr;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	G_CallBack_CTC();
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	G_CallBack_OVF();
	OVF_Number++;
}


void Timer1_init(TIMER0_PinConfig_t *pinConfig){

}
void Timer1_Stop(){

}

uint8 Timer1_GetCompareValue(){

}
void Timer1_SetCompareValue(uint8 value){

}

uint8 Timer1_GetCountValue(){

}
void Timer1_SetCountValue(uint8 value){

}

void Timer1_CallBack_CTC(void(*ptr)(void) ){

}
void Timer1_CallBack_Overflow(void(*ptr)(void) ){

}
