
#include "state.h"
#include "driver.h"


extern void(*P_next_state)();

enum {
	P_reading,
	P_waiting
}pressure_state_id;

void pressure_init();
STATE_define(P_reading);
STATE_define(P_waiting);