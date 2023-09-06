#include "alarm_acutator.h"

void(*Acutator_next_state)();

void startAlarm(){
	Acutator_next_state = STATE_ptr(Acutator_ON);
}
void stopAlarm(){
	Acutator_next_state = STATE_ptr(Acutator_OFF);
}

STATE_define(Acutator_init){
	//define state
	Acutator_state_id = Acutator_init;
	//update state 
	Acutator_next_state = STATE_ptr(Acutator_waiting);
	
}

STATE_define(Acutator_waiting){
	//define state
	Acutator_state_id = Acutator_waiting;
	
		
}

STATE_define(Acutator_ON){
	//define state
	Acutator_state_id = Acutator_ON;
	//Turn On Led
	Set_Alarm_actuator(0);
	//update state 
	Acutator_next_state = STATE_ptr(Acutator_waiting);
	
}
STATE_define(Acutator_OFF){
	//define state
	Acutator_state_id = Acutator_OFF;
	//Turn Off Led
	Set_Alarm_actuator(1);
	//update state 
	Acutator_next_state = STATE_ptr(Acutator_waiting);
}
