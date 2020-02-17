/*
 * game.h
 *
 *  Created on: 17 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#define RESET 1
#define DISPLAY_START 2
#define PREPARE_GAME 3
#define GAME 4
#define WIN 5
#define LOSE 6


void game();
int game_reset();
int game_display_start();
char* displayScore(int score);
void displayN7();
void game_win();

int score;
int game_launch;
int max2win;

int X_food;
int Y_food;

int current_result;
int current_state;

int distance;

/*Accelerometer */
int x_acc, y_acc;

char* scoreStr;
char* gameScoreStr;


char response_box_X;
char response_box_Y;

#endif /* SRC_GAME_H_ */
