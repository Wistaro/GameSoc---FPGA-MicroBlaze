/*
 * switchs.c
 *
 *  Created on: 3 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "switchs.h"

void initSwitchs(){

	Status_6_Gpio = XGpio_Initialize(&Gpio_6, GPIO_6_DEVICE_ID);

		if ( (Status_6_Gpio != XST_SUCCESS)) {
				xil_printf("Gpio Initialization Failed\r\n");
				return XST_FAILURE;
			}

		XGpio_SetDataDirection(&Gpio_6, 1, 0xFF);

}

int readAllSwitch(){

	int sw_val = XGpio_DiscreteRead(&Gpio_6, 1);

	return sw_val;

}

char readOneSwitch(int sw_nb){

	int sw_global = readAllSwitch();

	return (sw_global & (1<<(sw_nb-1))) >> (sw_nb - 1 );

}

