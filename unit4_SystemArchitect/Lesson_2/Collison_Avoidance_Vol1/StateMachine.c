/*
 * StateMachine.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#include "StateMachine.h"
int CA_speed=0, CA_distance=0, CA_threshold=50;
void(*next_state)();
STATE_define(CA_waiting){
	//define state
	CA_state_id = CA_waiting;
	CA_speed = 0;
	//state action
	CA_distance = US_distance_random(45,55,1);
	//check event
	(CA_distance <= CA_threshold) ?	(next_state = STATE_ptr(CA_waiting)) : (next_state = STATE_ptr(CA_driving));
	printf("waiting state : distance = %d , speed = %d\n", CA_distance, CA_speed);
}
STATE_define(CA_driving){
	//define state
		CA_state_id = CA_driving;
		CA_speed = 30;
		//state action
		CA_distance = US_distance_random(45,55,1);
		//check event
		(CA_distance <= CA_threshold) ?	(next_state = STATE_ptr(CA_waiting)) : (next_state = STATE_ptr(CA_driving));
		printf("Driving state : distance = %d , speed = %d\n", CA_distance, CA_speed);

}
int US_distance_random(int l, int r, int count){
	for(int i= 0 ; i <count ; i++){
		int rand_num = (rand() %(r-l +1) ) + l;
		return rand_num;
	}
	return 1;
}
