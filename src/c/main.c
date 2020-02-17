/*
 * main.c
 *
 *  Created on: 18 nov. 2019
 *      Authors: Wistaro & tyan
 */



//AXI GPIO driver
#include "xgpio.h"
//send data over UART
#include "xil_printf.h"
//information about AXI peripherals
#include "xparameters.h"

#include "tools.h"
#include "segments.h"
#include "accelero.h"
#include "box.h"
#include "screen.h"
#include "switchs.h"
#include "interrupt.h"
#include "game.h"

void main()
{
	init7seg();
	initAccelero();
	initBox();
	initScreen();
	initSwitchs();

	testInterrupt();

	game_launch = 0;

	while (1) //infinite loooooop :p
	{
		game();

	}
}



