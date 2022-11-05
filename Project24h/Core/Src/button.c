/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: USER
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;
int Key1Reg3 = NORMAL_STATE;

int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;

int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;
int Key3Reg3 = NORMAL_STATE;

int TimerForKey1Press = 1000;
int TimerForKey2Press = 1000;
int TimerForKey3Press = 1000;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKey1Process(){
	button1_flag = 1;
}
void subKey2Process(){
	button2_flag = 1;
}
void subKey3Process(){
	button3_flag = 1;
}
void getKey1Input(){
	Key1Reg0 = Key1Reg1;
	Key1Reg1 = Key1Reg2;
	Key1Reg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2)){
		if(Key1Reg3 != Key1Reg2){
			Key1Reg3 = Key1Reg2;
			if(Key1Reg2 == PRESSED_STATE){
				TimerForKey1Press = 1000;
				subKey1Process();
			}
		}else {
			TimerForKey1Press--;
			if(TimerForKey1Press == 0){
				Key1Reg3 = NORMAL_STATE;
			}
		}
	}
}
void getKey2Input(){
	Key2Reg0 = Key2Reg1;
	Key2Reg1 = Key2Reg2;
	Key2Reg2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2)){
		if(Key2Reg3 != Key2Reg2){
			Key2Reg3 = Key2Reg2;
			if(Key2Reg2 == PRESSED_STATE){
				TimerForKey2Press = 1000;
				subKey2Process();
			}
		}else {
			TimerForKey2Press--;
			if(TimerForKey2Press == 700){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 600){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 500){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 400){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 300){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 200){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 100){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
			if(TimerForKey2Press == 0){
				if(Key2Reg2 == PRESSED_STATE){
					subKey2Process();
				}
			}
		}
	}
}
void getKey3Input(){
	Key3Reg0 = Key3Reg1;
	Key3Reg1 = Key3Reg2;
	Key3Reg2 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if((Key3Reg0 == Key3Reg1) && (Key3Reg1 == Key3Reg2)){
		if(Key3Reg3 != Key3Reg2){
			Key3Reg3 = Key3Reg2;
			if(Key3Reg2 == PRESSED_STATE){
				TimerForKey3Press = 1000;
				subKey3Process();
			}
		}else {
			TimerForKey3Press--;
			if(TimerForKey3Press == 700){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 600){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 500){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 400){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 300){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 200){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 100){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
			if(TimerForKey3Press == 0){
				if(Key3Reg2 == PRESSED_STATE){
					subKey3Process();
				}
			}
		}
	}
}
