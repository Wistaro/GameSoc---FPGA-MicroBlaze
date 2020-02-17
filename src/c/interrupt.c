/*
 * interrupt.c
 *
 *  Created on: 4 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "interrupt.h"




/*****************************************************************************/
/**
*
* This is the main function for the Interrupt Controller example. This
* function is not included if the example is generated from the TestAppGen test
* tool.
*
* @param	None.
*
* @return	XST_SUCCESS to indicate success, otherwise XST_FAILURE.
*
* @note		None.
*
******************************************************************************/
#ifndef TESTAPP_GEN

int testInterrupt(void)
{
	int Status;

	/*
	 *  Run the Intc example , specify the Device ID generated in
	 * xparameters.h.
	 */
	Status = IntcSelfTestExample(INTC_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("Intc tapp Example Failed\r\n");
		return XST_FAILURE;
	}

	xil_printf("Successfully ran Intc tapp Example\r\n");
	return XST_SUCCESS;

}
#endif

/*****************************************************************************/
/**
*
* This function runs a self-test on the driver/device. This is a destructive
* test. This function is an example of how to use the interrupt controller
* driver component (XIntc) and the hardware device.  This function is designed
* to work without any hardware devices to cause interrupts.  It may not return
* if the interrupt controller is not properly connected to the processor in
* either software or hardware.
*
* This function relies on the fact that the interrupt controller hardware
* has come out of the reset state such that it will allow interrupts to be
* simulated by the software.
*
* @param	DeviceId is device ID of the Interrupt Controller Device,
*		typically XPAR_<INTC_instance>_DEVICE_ID value from
*		xparameters.h.
*
* @return	XST_SUCCESS to indicate success, otherwise XST_FAILURE.
*
* @note		None.
*
******************************************************************************/
int IntcSelfTestExample(u16 DeviceId)
{
	int Status;

	/*
	 * Initialize the interrupt controller driver so that it is ready to use.
	 */
	Status = XIntc_Initialize(&InterruptController, DeviceId);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


	/*
	 * Perform a self-test to ensure that the hardware was built correctly.
	 */
	Status = XIntc_SelfTest(&InterruptController);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}


/*****************************************************************************/
/**
*
* This function is used by the TestAppGen generated application to setup
* the interrupt controller.
*
* @param	IntcInstancePtr is the reference to the Interrupt Controller
*		instance.
* @param	DeviceId is device ID of the Interrupt Controller Device,
*		typically XPAR_<INTC_instance>_DEVICE_ID value from
*		xparameters.h.
*
* @return	XST_SUCCESS to indicate success, otherwise XST_FAILURE.
*
* @note		None.
*
******************************************************************************/
int IntcInterruptSetup(XIntc *IntcInstancePtr, u16 DeviceId)
{

	int Status;

	/*
	 * Initialize the interrupt controller driver so that it is
	 * ready to use.
	 */
	Status = XIntc_Initialize(IntcInstancePtr, DeviceId);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Perform a self-test to ensure that the hardware was built  correctly.
	 */
	Status = XIntc_SelfTest(IntcInstancePtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Initialize the exception table.
	 */
	Xil_ExceptionInit();

	/*
	 * Register the interrupt controller handler with the exception table.
	 */
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XIntc_DeviceInterruptHandler,
			(void*) 0);

	/*
	 * Enable exceptions.
	 */
	Xil_ExceptionEnable();

	/*
	 * Start the interrupt controller such that interrupts are enabled for
	 * all devices that cause interrupts.
	 */
	Status = XIntc_Start(IntcInstancePtr, XIN_REAL_MODE);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}

