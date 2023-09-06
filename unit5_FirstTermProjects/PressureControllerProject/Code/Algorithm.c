#include "Algorithm.h"


int G_pressureVal =0,  pressure_Threshold = 20;

void(*Alogrithm_next_state)();

void pressure_set_value(int pVal){
	
	// get value
	G_pressureVal = pVal;	
	// update state
	Alogrithm_next_state = STATE_ptr(Detect_High_Pressure);
	

}	

STATE_define(Detect_High_Pressure){
	//define state
	Alogrithm_state_id = Detect_High_Pressure;
	
	if(	G_pressureVal  >= pressure_Threshold ){
		HighPressure_Detected();
	}
	
	Alogrithm_next_state = STATE_ptr(Detect_High_Pressure);
}