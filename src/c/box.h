/*
 * box.h
 *
 *  Created on: 2 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_BOX_H_
#define SRC_BOX_H_

#define FRAME_WIDTH 1920
#define FRAME_LENGTH 1080

#define BOX_SIZE 30

#define MAX_X FRAME_WIDTH-BOX_SIZE
#define MAX_Y FRAME_LENGTH-85

#define MIN_X 245
#define MIN_Y 0

#define BOX_X_INIT FRAME_WIDTH/2
#define BOX_Y_INIT FRAME_LENGTH/2

#include"math.h"
#include "xgpio.h"

int x_box; 
int y_box; 

void initBox();
int getXBox();
int getYBox();

char updateXBox(int acc_X, char difficulty);
char updateYBox(int acc_Y, char difficulty);

#endif /* SRC_BOX_H_ */
