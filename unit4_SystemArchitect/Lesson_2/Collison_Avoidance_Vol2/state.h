/*
 * state.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Alaa
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE_ptr(_stateFun_) ST_##_stateFun_

// state connections
void US_set_distance(int distance);
void DC_motor(int speed);
#endif /* STATE_H_ */
