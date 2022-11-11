/*
 * DC_motor.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */



#include "DC_motor.h"
int DC_speed=0;
void(*DC_next_state)();
void DC_motor(int speed){
	DC_speed = speed;
	DC_state_id = DC_busy;
	DC_next_state = STATE_ptr(DC_busy);
	printf("DC-----speed = %d------CA\n", DC_speed);
}
STATE_define(DC_busy){
	//define state
	DC_state_id = DC_busy;
		DC_next_state = STATE_ptr(DC_idle);
	printf("DC_busy : speed = %d\n", DC_speed);




}
STATE_define(DC_idle){
	DC_state_id = DC_idle;
	DC_next_state = STATE_ptr(DC_idle);
	printf("DC_idle : speed = %d\n", DC_speed);
}
void DC_init(){

	printf("DC_init\n");
}

