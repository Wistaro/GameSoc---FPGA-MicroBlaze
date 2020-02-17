/*
 * box.c
 *
 *  Created on: 2 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "box.h"

void initBox(){
	x_box = BOX_X_INIT;
	y_box = BOX_Y_INIT;
}

int getXBox(){
	return x_box;
}

int getYBox(){
	return y_box;
}

char updateXBox(int acc_X, char difficulty){

	if(acc_X < 246 && x_box > 0){

		x_box = x_box - (int)(abs( (acc_X / 10) - 25 )) * 5*(1 + (3/2)*difficulty);

	}else if(acc_X >= 246 && x_box < FRAME_WIDTH){

		x_box = x_box + (int)(abs( (acc_X / 10) - 25 )) * 5*(1 + (3/2)*difficulty);
	}

	if(x_box < MIN_X){
		x_box = MIN_X;
		return 1;
	}
	else if(x_box > MAX_X){
		x_box = MAX_X;
		return 1;
	}
	else{
		return 0;
	}

}

char updateYBox(int acc_Y, char difficulty){
	if(acc_Y < 246 && y_box > 0){

		y_box = y_box - (int)(abs( (acc_Y / 10) - 25 )) * 5*(1 + (3/2)*difficulty);

	}else if(acc_Y >= 246 && y_box < FRAME_LENGTH){

		y_box = y_box + (int)(abs( (acc_Y / 10) - 25 )) * 5*(1 + (3/2)*difficulty);
	}
	else{}

	if(y_box < MIN_Y){
		y_box = MIN_Y;
		return 1;
	}
	else if(y_box > MAX_Y){
		y_box = MAX_Y;
		return 1;
	}
	else{
		return 0;
	}
}



