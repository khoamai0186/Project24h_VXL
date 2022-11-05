/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: USER
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "global.h"

#define INIT 0
#define LAMLAI 1
#define TANG 2
#define GIAM 3
#define BINHTHUONG 4


void fsm_simple_buttons_run ();
void display7SEG(int num);
#endif /* INC_FSM_H_ */
