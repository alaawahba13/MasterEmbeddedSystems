/*
 * DC_motor.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "state.h"


STATE_define(DC_idle);
STATE_define(DC_busy);
void DC_init();

extern void(*DC_next_state)();
enum {
	DC_idle,
	DC_busy
}DC_state_id;


#endif /* DC_MOTOR_H_ */
