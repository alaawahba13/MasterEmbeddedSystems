/*
 * ADC.c
 *
 *  Created on: 10 Aug 2023
 *      Author: Alaa Wahba
 */

#include "ADC.h"

void (*G_CallBack)(void);
void ADC_init(ADC_pinConfig_t *pin_Config){
   ADMUX |= pin_Config->vref;
   ADMUX |= pin_Config->adjust;

   if( pin_Config->INT_Enable == ENABLE){
	   SET(ADCSRA,ADIE);
	   G_CallBack = pin_Config->CallBack_Ptr;
   }
   else
	   CLEAR(ADCSRA,ADIE);

   if(pin_Config->mode == FREE_RUNNING)
	   SET(ADCSRA,ADATE);

   ADCSRA |= pin_Config->prescalar;

   SET(ADCSRA,ADEN);


}
void ADC_Deinit(){
	ADMUX = 0x00;
	ADCSRA = 0x00;

}
uint16 ADC_Read(ADC_CHANNEL_t ADCx){
	//Select Channel
	ADMUX &=0xE0;
	ADMUX |= ADCx;
	//Start conversion
	SET(ADCSRA,ADSC);
	//Wait
	while(!GET(ADCSRA,ADSC));

	return ADC;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	G_CallBack();
}
