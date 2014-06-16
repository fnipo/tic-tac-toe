/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <board3d.h>
#include <util.h>

static void MakeFakeMoves();

int main(void) {

	puts("Welcome to Tic Tac Toe 3D!");

	MakeFakeMoves();

	BOARD3D_PrintBoard();

	//UTIL_ClearConsole();

	return EXIT_SUCCESS;
}

static void MakeFakeMoves() {
	BOARD3D_MakeAMove(PLAYER_1, 0, 0, 0);
	BOARD3D_MakeAMove(PLAYER_1, 0, 0, 1);
	BOARD3D_MakeAMove(PLAYER_1, 0, 0, 2);

	BOARD3D_MakeAMove(PLAYER_2, 0, 2, 0);
	BOARD3D_MakeAMove(PLAYER_2, 1, 2, 0);
	BOARD3D_MakeAMove(PLAYER_2, 2, 2, 0);

	BOARD3D_MakeAMove(PLAYER_1, 0, 1, 2);
	BOARD3D_MakeAMove(PLAYER_1, 0, 2, 2);

	BOARD3D_MakeAMove(PLAYER_2, 1, 1, 1);
	BOARD3D_MakeAMove(PLAYER_2, 2, 0, 2);
}
