/*
 * Timer.h
 *
 *  Created on: 2 Aug 2023
 *      Author:  Alaa Wahba
 */

#ifndef ATMEGA32_INC_TIMER_H_
#define ATMEGA32_INC_TIMER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Atmega32.h"
#include "../../Library/BIT_MATH.h"

//-----------------------------
// Configuration Refrences
//-----------------------------

typedef enum{
	NORMAL,
	PWM_PHASE_CORRECT = 0x40,
	CTC = 0x08,
	FAST_PWM =0x48
}MODES_t;


typedef enum{
	NONE,
	CLK,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024,
	EXT_CLK_FALLING_EDGE,
	EXT_CLK_RISING_EDGE
}CLOCK_SELECT_t;

typedef enum{
	OCIE_DISABLE,
	OCIE_ENABLE = 0x02

}OCIE_t;


typedef enum{
	TOIE_DISABLE,
	TOIE_ENABLE
}TOIE_t;


typedef struct{
	MODES_t mode;
	CLOCK_SELECT_t clk;
	OCIE_t OCIE;
	TOIE_t TOIE;
	uint8 OC0;
}TIMER0_PinConfig_t;

/*
 * @ref OC0
 */
#define NORMAL_MODE 		0x00
#define NON_PWM_TOGGLE 		0x10
#define NON_PWM_CLEAR 		0x20
#define NON_PWM_SET			0x30

#define PWM_INVERTING 		0x30
#define PWM_NON_INVERTING 	0x20

/*
* ===============================================
* APIs Supported by "TIMER0 DRIVER"
* ===============================================
*/

void Timer0_init(TIMER0_PinConfig_t *pinConfig);
void Timer0_Stop();

uint8 Timer0_GetCompareValue();
void Timer0_SetCompareValue(uint8 value);

uint8 Timer0_GetCountValue();
void Timer0_SetCountValue(uint8 value);

uint8 Timer0_GetOverflowValue();
void Timer0_SetOverflowValue(uint8 value);

void Timer0_CallBack_CTC(void(*ptr)(void) );
void Timer0_CallBack_Overflow(void(*ptr)(void) );




#endif /* ATMEGA32_INC_TIMER_H_ */
