
#include "state.h"
#include "driver.h"


extern void(*Alarm_next_state)();
#define timer_delay 		10000

enum {
	Alarm_ON,
	Alarm_OFF,
	Alarm_waiting
}Alarm_state_id;

STATE_define(Alarm_ON);
STATE_define(Alarm_OFF);
STATE_define(Alarm_waiting);