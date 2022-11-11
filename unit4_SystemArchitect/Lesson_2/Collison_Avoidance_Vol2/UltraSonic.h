/*
 * UltraSonic.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "state.h"

STATE_define(US_busy);

void US_init();
extern void(*US_next_state)();
enum {
	US_busy,
}US_state_id;


#endif /* ULTRASONIC_H_ */
