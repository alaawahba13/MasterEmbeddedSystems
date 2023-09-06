#include "state.h"

extern void(*Alogrithm_next_state)();

enum {
	Detect_High_Pressure,
}Alogrithm_state_id;

STATE_define(Detect_High_Pressure);