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
#include <strings.h>

static int GetUserOption(int minOption, int maxOption);
static void MakeFakeMoves();
static void PrintHeader();
static void PrintMainMenu();
static void PrintGameModeSubMenu();
static void PrintRanking();
static void HandleMainMenu();
static void HandleGameModeSubMenu(int c);

int main(void) {
	PrintMainMenu();
	HandleMainMenu();

	return EXIT_SUCCESS;
}

static int GetUserOption(int minOption, int maxOption) {
	int option;

	while(TRUE) {
		char c = getchar();
		if(c >= minOption && c <= maxOption) {
			option = atoi(&c);
		} else {
			puts(STRING_BAD_OPTION);
			continue;
		}
	}

	return option;
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

static void PrintHeader() {
	if(BOARD3D_GameBoardIsEmpty()) {
		BOARD3D_Init();
		MakeFakeMoves();
	}
	UTIL_ClearConsole();
	puts(STRING_WELCOME_MESSAGE);
	BOARD3D_PrintBoard();
	printf(NEW_LINE_CHAR);
}

static void PrintMainMenu() {
	PrintHeader();
	puts(STRING_MAIN_MENU_OPTION1);
	puts(STRING_MAIN_MENU_OPTION2);
	puts(STRING_MAIN_MENU_OPTION3);

	printf(NEW_LINE_CHAR);
	puts(STRING_REQUEST_OPTION);
}

static void PrintGameModeSubMenu() {
	PrintHeader();
	puts(STRING_GAMEMODE_SUBMENU_OPTION1);
	puts(STRING_GAMEMODE_SUBMENU_OPTION2);
	puts(STRING_BACK_OPTION);

	printf(NEW_LINE_CHAR);
	puts(STRING_REQUEST_OPTION);
}

static void PrintRanking() {
	PrintHeader();
	puts("1 - Náutico");
	puts("2 - Real Madrid");
	puts("3 - Barcelona");
	puts("4 - Santa Cruz");
	puts("5 - Ibis");
	puts("6 - Sport");

	printf(NEW_LINE_CHAR);
	puts(STRING_BACK_OPTION);
}

static void HandleMainMenu() {
	int option = GetUserOption(MAINMENU_MIN_OPTION, MAINMENU_MAX_OPTION);

	if(option == MAINMENU_PLAY) {
		PrintGameModeSubMenu();
		HandleGameModeSubMenu(getchar());
	} else if(option == MAINMENU_RANKING) {
		PrintRanking();
		//HandleRanking(getchar());
	} else if(option == MAINMENU_QUIT) {
		exit(0);
	}
}

static void HandleGameModeSubMenu(int c) {
	if(GAMEMENU_BOARD3D) {
		"Start BOARD 3D";
	} else if(GAMEMENU_BOARD4D) {
		"Start BOARD 4D";
	} else if(BACK_OPTION) {
		PrintMainMenu();
	}
}
