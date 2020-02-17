/*
 * screen.c
 *
 *  Created on: 3 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "screen.h"

void initScreen()
{
	Status_4_Gpio = XGpio_Initialize(&Gpio_4, GPIO_4_DEVICE_ID);
	Status_5_Gpio = XGpio_Initialize(&Gpio_5, GPIO_5_DEVICE_ID);

	if ( (Status_4_Gpio != XST_SUCCESS) || (Status_5_Gpio != XST_SUCCESS) ) {
			xil_printf("Gpio4&5 Initialization Failed\r\n");
		}

	XGpio_SetDataDirection(&Gpio_4, 1, 0x00);
	XGpio_SetDataDirection(&Gpio_5, 1, 0x00);
}

void writeXBox(int coord_X)
{
	XGpio_DiscreteWrite(&Gpio_4, 1, coord_X);
}

void writeYBox(int coord_Y)
{
	XGpio_DiscreteWrite(&Gpio_5, 1, coord_Y);
}
