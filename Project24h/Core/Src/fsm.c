/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: USER
 */


#include "fsm.h"


void display7SEG(int num){
	switch(num){
	case 0:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 1);
		break;
	}
	case 1:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 1);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 1);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 1);
		break;
	}
	case 2:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 1);
		break;
	}
	case 3:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		break;
	}
	case 4:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 1);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 1);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		break;
	}
	case 5:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 1);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		break;
	}
	case 6:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		break;
	}
	case 7:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 1);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 1);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 1);
		break;
	}
	case 8:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		break;
	}
	case 9:{
		HAL_GPIO_WritePin(CA_GPIO_Port, CA_Pin, 0);
		HAL_GPIO_WritePin(CB_GPIO_Port, CB_Pin, 0);
		HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, 0);
		HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, 0);
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);
		HAL_GPIO_WritePin(CF_GPIO_Port, CF_Pin, 0);
		HAL_GPIO_WritePin(CG_GPIO_Port, CG_Pin, 0);
		break;
	}
	default: break;
	}
}

void fsm_simple_buttons_run (){
	display7SEG(count);
	switch(status){
	case INIT:{

		setTimer2(10000);
		status = BINHTHUONG;

		break;
	}
	case LAMLAI:{
		display7SEG(0);
		count = 0;
		status = INIT;
		break;
	case TANG:
		count++;
		if(count>9){
			count = 0;
		}
		display7SEG(count);
		status = INIT;
		break;
	}
	case GIAM:{
		count--;
		if(count<0){
			count = 9;
		}
		display7SEG(count);

		status = INIT;
		break;
	}
	case BINHTHUONG:{

		if(isButton1Pressed() == 1){
			status = LAMLAI;
		}
		if(isButton2Pressed() == 1){
			status = TANG;
		}
		if(isButton3Pressed() == 1){
			status = GIAM;
		}
		if(timer2_flag==1){
			if(timer3_flag==1){
				count--;
				if(count<=0){
					count=0;
					display7SEG(count);
				}
				display7SEG(count);
				setTimer3(1000);
			}
		}
		break;

	}
	default:
		break;
	}
}
