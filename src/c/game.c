/*
 * game.c
 *
 *  Created on: 17 dec. 2019
 *      Authors: Wistaro & tyan
 */

#include "segments.h"
#include "game.h"
#include "tools.h"
#include "switchs.h"
#include "accelero.h"
#include "box.h"
#include <string.h>
#include <math.h>

int game_reset(){
	distance = 0;
	score = 0;
	display7Seg("HELLO");
	X_food = 0;
	Y_food = 0;
	max2win = 10;

	return 1;
}

int game_display_start(){
	score = 0;
	display7Seg("START ?");
	return 1;
}

int prepare_game(){
	score = 0;
	display7Seg("LOADING");
	X_food = rnd(MIN_X + 100,MAX_X - 100);
	Y_food = rnd(MIN_Y + 100,MAX_Y - 100);

	Dly_ms(1000);

	return 1;
}

void game_win(){
	display7Seg("SUCCESS!");
}

int mainGame(){


	display7Seg(displayScore(score));


	x_acc = readX_accelero();
	y_acc = readY_accelero();

	response_box_X = updateXBox(x_acc, readOneSwitch(15));
	response_box_Y = updateYBox(y_acc, readOneSwitch(15));

	if(response_box_X == 1 || response_box_Y == 1){
		score = 0;
	}

	if(readOneSwitch(14) == 1){
		max2win = 10;
	}else{
		if(score >= 5){
			current_state = WIN;
		}else{

		max2win = 5;

		}
	}


	Dly_ms(5);

	writeXBox(x_box);
	writeYBox(y_box);

	Dly_ms(10);

	writeXBox(X_food);
	writeYBox(Y_food);

	distance = abs(X_food - x_box)*abs(X_food - x_box) + abs(Y_food - y_box)*abs(Y_food - y_box);

	if(distance < 300){
		score = score + 1;
		X_food = rnd(200,1100);
		Y_food = rnd(200,1100);
	}
	else{
		score = score;
	}


}
char* displayScore(int score){

	char* displayscore = "";

	 switch ( score )
	      {
	 	 	 case 0: displayscore = "SCORE 0"; break;
	         case 1: displayscore = "SCORE 1"; break;
	         case 2: displayscore = "SCORE 2"; break;
	         case 3: displayscore = "SCORE 3"; break;
	         case 4: displayscore = "SCORE 4"; break;
	         case 5: displayscore = "SCORE 5"; break;
	         case 6: displayscore = "SCORE 6"; break;
	         case 7: displayscore = "SCORE 7"; break;
	         case 8: displayscore = "SCORE 8"; break;
	         case 9: displayscore = "SCORE 9"; break;
	         case 10: displayscore = "SCORE 10"; break;
	         default: displayscore = "SCORE ?";
	      }

	return displayscore;
}


void game(){

	if(game_launch == 0){
		current_result = game_reset();
		current_state = RESET;
		game_launch = 1;

	}

	if(current_state == RESET){

		current_result = game_reset();
		Dly_ms(2000);

		if(current_result == 1){
			current_state = DISPLAY_START;
		}
		else{
			current_state = RESET;
		}
	}

	else if(current_state == DISPLAY_START){

		if(readOneSwitch(16) == 1){
			displayN7();
		}

			current_result = game_display_start();
		if(readOneSwitch(1)){
			current_state = PREPARE_GAME;
		}
		else{
			current_state = DISPLAY_START;
		}
	}

	else if(current_state == PREPARE_GAME){


		current_state  = prepare_game();

		if(current_result == 1 ){
			current_state = GAME;
		}
		else{
			current_state = PREPARE_GAME;
		}
	}

	else if(current_state == GAME){
		mainGame();
		if(readOneSwitch(2)){
			current_state = RESET;
		}else if(score == max2win){
			current_state = WIN;
		}else{
			current_state = GAME;
		}

	}
	else if(current_state == WIN){
		game_win();
		Dly_ms(2000);
		current_state = RESET;

	}
}

void displayN7(){

			for(int i = 0; i<=200; i = i + BOX_SIZE/2){
				// N
				writeXBox(200 + FRAME_WIDTH/2 - 400);
				writeYBox(i + FRAME_LENGTH/2 - 200);


				writeXBox(200 + i+ FRAME_WIDTH/2 - 400);
				writeYBox(i+ FRAME_LENGTH/2- 200);


				writeXBox(400+ FRAME_WIDTH/2 - 400);
				writeYBox(i+ FRAME_LENGTH/2- 200);


				writeXBox(700+ FRAME_WIDTH/2 - 400);
				writeYBox(i+ FRAME_LENGTH/2- 200);
			}
			for(int i = 550; i<=700; i = i + BOX_SIZE/2){
				writeXBox(i+ FRAME_WIDTH/2 - 400);
				writeYBox(0+ FRAME_LENGTH/2- 200);

			}
			for(int i = 650; i<=750; i = i + BOX_SIZE/2){
				writeXBox(i+ FRAME_WIDTH/2 - 400);
				writeYBox(100+ FRAME_LENGTH/2- 200);
			}
}

