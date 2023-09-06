
#include "driver.h"
#include "pressure_sensor.h"
#include "Algorithm.h"
#include "alarm_acutator.h"
#include "alarm_monitor.h"


void setup(){
	GPIO_INITIALIZATION();
	pressure_init();
	Alogrithm_next_state = STATE_ptr(Detect_High_Pressure);
	Acutator_next_state = STATE_ptr(Acutator_init);
	Alarm_next_state = STATE_ptr(Alarm_OFF);
	
}

int main(void)
{
	
	setup();


	while (1)
	{
			
		P_next_state();
		Alogrithm_next_state();
		Alarm_next_state();
		Acutator_next_state();

	}
}
