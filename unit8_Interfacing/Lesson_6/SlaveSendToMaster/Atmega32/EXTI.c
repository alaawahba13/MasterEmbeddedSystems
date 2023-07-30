/*
 * EXTI.c
 *
 *  Created on: 29 Jul 2023
 *      Author: Alaa Wahba
 */

#include "EXTI.h"
void (*G_Ptr[3])(void);
void EXTI_Enable(uint8 Index, uint8 Edge) {
	switch (Index) {
	case EXTI0_Index:
		switch (Edge) {
		case Low_Level:
			CLEAR(MCUCR, 0);
			CLEAR(MCUCR, 1);
			break;
		case Any_change:
			SET(MCUCR, 0);
			CLEAR(MCUCR, 1);
			break;
		case Falling_Edge:
			CLEAR(MCUCR, 0);
			SET(MCUCR, 1);
			break;
		case Rising_Edge:
			SET(MCUCR, 0);
			SET(MCUCR, 1);
			break;
		}
		break;
	case EXTI1_Index:
		switch (Edge) {
		case Low_Level:
			CLEAR(MCUCR, 2);
			CLEAR(MCUCR, 3);
			break;
		case Any_change:
			SET(MCUCR, 2);
			CLEAR(MCUCR, 3);
			break;
		case Falling_Edge:
			CLEAR(MCUCR, 2);
			SET(MCUCR, 3);
			break;
		case Rising_Edge:
			SET(MCUCR, 2);
			SET(MCUCR, 3);
			break;
		}
		break;
	case EXTI2_Index:
		switch (Edge) {
		case Falling_Edge:
			CLEAR(MCUCSR, 6);
			break;
		case Rising_Edge:
			SET(MCUCSR, 6);
			break;
		}
		break;
	}
	SET(SREG,7);   // enable global interrupt;
	SET(GICR, Index);
}

void EXTI_Disable(uint8 Index) {
	CLEAR(SREG,7);
	CLEAR(GICR, Index);

}

void EXTI_setCallBackFunction(uint8 Index, void (*Ptr)(void)) {
	G_Ptr[Index] = Ptr;

}

void __vector_1(void)			__attribute__((signal));
void __vector_1(void){
	G_Ptr[0]();
}


void __vector_2(void)			__attribute__((signal));
void __vector_2(void){
	G_Ptr[1]();
}


void __vector_3(void)			__attribute__((signal));
void __vector_3(void){
	G_Ptr[2]();
}
