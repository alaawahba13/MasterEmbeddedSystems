/*
 * StateMachine.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "state.h"


STATE_define(CA_driving);
STATE_define(CA_waiting);
extern void(*CA_next_state)();

enum {
	CA_waiting,
	CA_driving
}CA_state_id;



#endif /* STATEMACHINE_H_ */
