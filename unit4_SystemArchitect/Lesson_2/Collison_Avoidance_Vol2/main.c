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
#include "DC_motor.h"
#include "UltraSonic.h"

void setup(){
	DC_init();
	US_init();
	CA_next_state = STATE_ptr(CA_waiting);
	US_next_state = STATE_ptr(US_busy);
	DC_next_state = STATE_ptr(DC_idle);

}
int main(void) {
	setup();
	 while(1){
		 US_next_state();
		 CA_next_state();
		 DC_next_state();
		 for(int i =0 ; i<5000; i++);
	 }
	return EXIT_SUCCESS;
}
