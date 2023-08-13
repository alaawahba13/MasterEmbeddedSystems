/*
 * GI.c
 *
 *  Created on: 6 Aug 2023
 *      Author: Alaa Wahba
 */

#include "GI.h"
void GI_Enable(){
	SET(SREG,I);
}
void GI_Disable(){
	CLEAR(SREG,I);
}
