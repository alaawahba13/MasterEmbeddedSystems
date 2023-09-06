#include "alarm_monitor.h"


 void(*Alarm_next_state)();


void HighPressure_Detected(){
	//update state
	Alarm_next_state  = STATE_ptr(Alarm_ON);
	
}
STATE_define(Alarm_OFF){
	//define state
	Alarm_state_id = Alarm_OFF;
	//Send stop alarm 
	stopAlarm();
	
	
}
STATE_define(Alarm_ON){
	//define state
	Alarm_state_id = Alarm_ON;
	//Send start alarm 
	startAlarm();
	//update state
	Alarm_next_state  = STATE_ptr(Alarm_waiting);
	
}
STATE_define(Alarm_waiting){
	//define state
	Alarm_state_id = Alarm_waiting;
	//delay 
	Delay(timer_delay);
	//update state
	Alarm_next_state  = STATE_ptr(Alarm_OFF);
	
}