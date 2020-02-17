/*
 * segments.h
 *
 *  Created on: 25 nov. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_SEGMENTS_H_
#define SRC_SEGMENTS_H_

#include"math.h"
#include "xgpio.h"

#define GPIO_1_DEVICE_ID XPAR_GPIO_1_DEVICE_ID
#define GPIO_2_DEVICE_ID XPAR_GPIO_2_DEVICE_ID

unsigned int getDataWithString(char* input_string);
void init7seg();
void display7Seg(char* str_disp);

XGpio Gpio_1;
XGpio Gpio_2;

int Status_1_Gpio;
int Status_2_Gpio;

char* buff_str_dgb;

#endif /* SRC_SEGMENTS_H_ */
