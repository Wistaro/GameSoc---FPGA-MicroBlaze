/*
 * accelero.c
 *
 *  Created on: 2 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "accelero.h"

void initAccelero()
{
		Status_0_Gpio = XGpio_Initialize(&Gpio_0, GPIO_0_DEVICE_ID);
		Status_3_Gpio = XGpio_Initialize(&Gpio_3, GPIO_3_DEVICE_ID);

		if ( (Status_0_Gpio != XST_SUCCESS) || (Status_3_Gpio != XST_SUCCESS) ) {
				xil_printf("Gpio Initialization Failed\r\n");
			}

		XGpio_SetDataDirection(&Gpio_0, 1, 0xFF);
		XGpio_SetDataDirection(&Gpio_3, 1, 0xFF);
}

int readY_accelero()
{
	readX_value = XGpio_DiscreteRead(&Gpio_0, 1);
	return readX_value;
}

int readX_accelero()
{
	readY_value = XGpio_DiscreteRead(&Gpio_3, 1);
	return readY_value;
}


