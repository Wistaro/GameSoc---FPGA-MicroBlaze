/*
 * segments.c
 *
 *  Created on: 25 nov. 2019
 *      Authors: Wistaro & tyan
 */

#include "segments.h"

unsigned int getDataWithString(char* input_string){

	unsigned int val_output = 0;

	unsigned int global_val = 0;

	int i = 0;
	int cpt_pow = 0;

	char current_char = 0;

	for(i = 0; i<4; i++){

		current_char = input_string[i];

		if( (current_char <= '9') && (current_char >= '0') ){
			val_output = (int)(current_char - 48);
		}
		else{
			switch(current_char){

				case 'A':
					val_output = 10;
				  break;

				case 'B':
					val_output = 20;
				  break;

				case 'C':
					val_output = 12;
				  break;

				case 'D':
					val_output = 25;
				  break;

				case 'E':
					val_output = 23;
				  break;

				case 'F':
					val_output = 15;
				  break;

				case 'G':
					val_output = 19;
				  break;

				case 'I':
					val_output = 24;
				  break;

				case 'L':
					val_output = 16;
				  break;

				case 'N':
					val_output = 17;
				  break;

				case 'O':
					val_output = 0;
				  break;

				case 'P':
					val_output = 21;
				  break;

				case 'R':
					val_output = 11;
				  break;

				case 'U':
					val_output = 22;
				  break;

				case 'H':
					val_output = 18;
					break;

				case '-':
					val_output = 13;
					break;

				case ' ':
					val_output = 31;
					break;

				case 'S':
					val_output = 5;
					break;

				case 'T':
					val_output = 14;
					break;

				case 'J':
					val_output = 26;
					break;

				case 'K':
					val_output = 27;
					break;

				case 'M':
					val_output = 28;
					break;

				case '_':
					val_output = 29;
					break;

				case '?':
					val_output = 30;
					break;

				default:
					val_output = 31;
			}
	}

		if(i == 0){
			cpt_pow = 32768;
		}else if(i == 1){
			cpt_pow = 1024;
		}else if(i == 2){
			cpt_pow = 32;
		}else if(i == 3){
			cpt_pow = 1;
		}

		global_val+=val_output * cpt_pow;

	}

	return global_val;

}

void init7seg(){

	Status_1_Gpio = XGpio_Initialize(&Gpio_1, GPIO_1_DEVICE_ID);
	Status_2_Gpio = XGpio_Initialize(&Gpio_2, GPIO_2_DEVICE_ID);

	if ( (Status_1_Gpio != XST_SUCCESS) || (Status_2_Gpio != XST_SUCCESS) ) {
			xil_printf("Gpio Initialization Failed\r\n");
			return XST_FAILURE;
		}

	XGpio_SetDataDirection(&Gpio_1, 1, 0x00);
	XGpio_SetDataDirection(&Gpio_2, 1, 0x00);

}

void display7Seg(char* str_disp){

	if(str_disp != buff_str_dgb){
		xil_printf("%s", str_disp);
	}

	buff_str_dgb = str_disp;

	int data_0 = 0;
	int data_1 = 0;

	char* buff_0 = malloc(4*sizeof(char));
	char* buff_1 = malloc(4*sizeof(char));

	for(int i = 0; i<8; i++){

		if(i < 4){

			buff_0[i] = str_disp[i];

		}else{

			buff_1[i-4] = str_disp[i];
		}
	}

	data_0 = getDataWithString(buff_0);
	data_1 = getDataWithString(buff_1);

	XGpio_DiscreteWrite(&Gpio_1, 1, data_1);
	XGpio_DiscreteWrite(&Gpio_2, 1, data_0);

	free(buff_0);
	free(buff_1);

}
