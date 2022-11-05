/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
void subKey1Process();
void getKey1Input();

int isButton2Pressed();
void subKey2Process();
void getKey2Input();

int isButton3Pressed();
void subKey3Process();
void getKey3Input();


#endif /* INC_BUTTON_H_ */
