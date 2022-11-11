/*
 * StateMachine.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#include "StateMachine.h"

int CA_speed=0, CA_distance=0, CA_threshold=50;
void(*CA_next_state)();
void US_set_distance(int distance){
	CA_distance = distance;
	(CA_distance <= CA_threshold) ?	(CA_next_state = STATE_ptr(CA_waiting)) : (CA_next_state = STATE_ptr(CA_driving));
	printf("US-----speed=%d-----CA\n", CA_distance);
}
STATE_define(CA_waiting){
	//define state
	CA_state_id = CA_waiting;
	printf("waiting state : distance = %d , speed = %d\n", CA_distance, CA_speed);
	CA_speed = 0;
	DC_motor(CA_speed);

}
STATE_define(CA_driving){
	//define state
		CA_state_id = CA_driving;
		printf("Driving state : distance = %d , speed = %d\n", CA_distance, CA_speed);
		CA_speed = 30;

		DC_motor(CA_speed);

}

