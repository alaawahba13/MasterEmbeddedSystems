/*
 * StateMachine.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include <stdio.h>
#include <stdlib.h>
#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE_ptr(_stateFun_) ST_##_stateFun_
int US_distance_random(int l, int h, int count);
STATE_define(CA_driving);
STATE_define(CA_waiting);
extern void(*next_state)();
enum {
	CA_waiting,
	CA_driving
}CA_state_id;



#endif /* STATEMACHINE_H_ */
