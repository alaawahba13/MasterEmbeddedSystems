/*
 ============================================================================
 Name        : Collison_Avoidance.c
 Author      : Alaa Wahba
 Version     :
 Copyright   : Your copyright notice
 Description : Obstacle avoidance C, Ansi-style
 ============================================================================
 */


#include "StateMachine.h"

void setup(){
	next_state = STATE_ptr(CA_waiting);

}
int main(void) {
	setup();
	 while(1){
		 next_state();
		 for(int i =0 ; i<5000; i++);
	 }
	return EXIT_SUCCESS;
}
