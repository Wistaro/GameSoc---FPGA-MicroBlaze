/*
 * accelero.h
 *
 *  Created on: 2 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef ACCELERO_H_
#define ACCELERO_H_

#define GPIO_0_DEVICE_ID XPAR_GPIO_0_DEVICE_ID
#define GPIO_3_DEVICE_ID XPAR_GPIO_3_DEVICE_ID

#include"math.h"
#include "xgpio.h"

void initAccelero();
int readX_accelero();
int readY_accelero();

XGpio Gpio_0;
XGpio Gpio_3;

int Status_0_Gpio;
int Status_3_Gpio;

int readX_value;
int readY_value;

#endif /* ACCELERO_H_ */
