/*
 * UltraSonic.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#include "UltraSonic.h"
int US_distance=0;
void(*US_next_state)();
STATE_define(US_busy){
	//define state
	US_state_id = US_busy;
	//Read from US
	US_distance = US_distance_random(45,55,1);
	printf("US_busy : distance = %d\n", US_distance);
	//send distance
	US_set_distance(US_distance);
	US_next_state = STATE_ptr(US_busy);

}
void US_init(){

	printf("US_init\n");
}

int US_distance_random(int l, int r, int count){
	for(int i= 0 ; i <count ; i++){
		int rand_num = (rand() %(r-l +1) ) + l;
		return rand_num;
	}
	return 1;
}
