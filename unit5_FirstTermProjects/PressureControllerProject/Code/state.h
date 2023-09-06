

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE_ptr(_stateFun_) ST_##_stateFun_

// state connections
void pressure_set_value(int pVal);
void HighPressure_Detected();

void startAlarm(); 
void stopAlarm();

#endif /* STATE_H_ */
