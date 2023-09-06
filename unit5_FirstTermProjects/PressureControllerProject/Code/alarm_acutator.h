
#include "state.h"
#include "driver.h"


extern void(*Acutator_next_state)();

enum {
	Acutator_ON,
	Acutator_OFF,
	Acutator_waiting,
	Acutator_init
}Acutator_state_id;

STATE_define(Acutator_ON);
STATE_define(Acutator_OFF);
STATE_define(Acutator_waiting);
STATE_define(Acutator_init);