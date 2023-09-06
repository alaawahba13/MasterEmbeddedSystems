
#include "pressure_sensor.h"

int pVal=0;

void(*P_next_state)();

void pressure_init(){
	P_next_state  = STATE_ptr(P_waiting);
}

STATE_define(P_reading){
	//define state
	pressure_state_id = P_reading;
	//Read from sensor
	pVal = getPressureVal();
	//send value 
	pressure_set_value(pVal);
	//update state
	P_next_state  = STATE_ptr(P_waiting);
	
}
STATE_define(P_waiting){
	//define state
	pressure_state_id = P_waiting;
	//wait 
	Delay(2000);
	//update state
	P_next_state  = STATE_ptr(P_reading);
}