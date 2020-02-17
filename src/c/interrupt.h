/*
 * interrupt.h
 *
 *  Created on: 4 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_INTERRUPT_H_
#define SRC_INTERRUPT_H_

/******************************************************************************
*
* Copyright (C) 2002 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/
/******************************************************************************/
/**
*
* @file xintc_tapp_example.c
*
* This file contains a self test example using the Interrupt Controller driver
* (XIntc) and hardware device. Please reference other device driver examples to
* see more examples of how the Intc and interrupts can be used by a software
* application.
*
* This example shows the use of the Interrupt Controller both with a PowerPC405
* and MicroBlaze processor.
*
* The TestApp Gen utility uses this file to perform the self test and setup
* of Intc for interrupts.
*
* @note
*
* None
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver   Who  Date	 Changes
* ----- ---- -------- --------------------------------------------------------
* 1.00a sv   06/29/05  Created for Test App Integration
* 1.00c sn   05/09/06  Added Interrupt Setup Function
* 2.00a ktn  10/20/09  Updated to use HAL Processor APIs and minor changes as
*		       per coding guidelines.
* 3.6   ms   01/23/17 Added xil_printf statement in main function to
*                     ensure that "Successfully ran" and "Failed" strings
*                     are available in all examples. This is a fix for
*                     CR-965028.
* </pre>
******************************************************************************/

/***************************** Include Files *********************************/

#include "xparameters.h"
#include "xstatus.h"
#include "xintc.h"
#include "xil_exception.h"
#include "xil_printf.h"


/************************** Constant Definitions *****************************/

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place. This definition is not
 * included if the example is generated from the TestAppGen test tool.
 */
#ifndef TESTAPP_GEN
#define INTC_DEVICE_ID		  XPAR_INTC_0_DEVICE_ID
#endif

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/

int IntcSelfTestExample(u16 DeviceId);
int IntcInterruptSetup(XIntc *IntcInstancePtr, u16 DeviceId);

/************************** Variable Definitions *****************************/

static XIntc InterruptController; /* Instance of the Interrupt Controller */


#endif /* SRC_INTERRUPT_H_ */
