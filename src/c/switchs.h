/*
 * switchs.h
 *
 *  Created on: 3 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_SWITCHS_H_
#define SRC_SWITCHS_H_

#include "xgpio.h"

#define GPIO_6_DEVICE_ID XPAR_GPIO_6_DEVICE_ID

XGpio Gpio_6;

int Status_6_Gpio;

void initSwitchs();
int readAllSwitch();
char readOneSwitch(int sw_nb);

#endif /* SRC_SWITCHS_H_ */
