/*
 * screen.h
 *
 *  Created on: 3 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_SCREEN_H_
#define SRC_SCREEN_H_

#include "xgpio.h"

#define GPIO_4_DEVICE_ID XPAR_GPIO_4_DEVICE_ID
#define GPIO_5_DEVICE_ID XPAR_GPIO_5_DEVICE_ID

XGpio Gpio_4;
XGpio Gpio_5;

int Status_4_Gpio;
int Status_5_Gpio;

void initScreen();
void writeXBox(int coord_X);
void writeYBox(int coord_Y);

#endif /* SRC_SCREEN_H_ */
