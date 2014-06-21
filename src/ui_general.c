/*
 ============================================================================
 Name        : ui_general.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : UI to general modules
 ============================================================================
 */

/* Includes */
#include <ui_general.h>
#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <strings.h>
#include <util.h>
#include <ui_board3d.h>
#include <score.h>

static void PrintHeader();
static void PrintFakeBoard();
static void PrintMainMenu();
static void PrintGameModeSubMenu();
static void PrintRanking();
static void HandleMainMenu();
static void HandleGameModeSubMenu();
static void HandleRanking();

static PlayerInfo playerInfoArray[SCORE_MAX_PLAYERS];

void UIGENERAL_Start() {
	while(TRUE) {
		PrintMainMenu();
		HandleMainMenu();
	}
}

int UIGENERAL_GetUserOption(int minOption, int maxOption) {
	int option;

	while(TRUE) {
		int c = getchar();
		if(c != '\n') {
			option = atoi((char*)&c);
			if(option >= minOption && option <= maxOption) {
				break;
			} else {
				puts(STRING_BAD_OPTION);
			}
		}
	}

	return option;
}

static void PrintHeader() {
	UTIL_ClearConsole();
	puts(STRING_WELCOME_MESSAGE);
	PrintFakeBoard();
	printf(NEW_LINE_CHAR);
}

static void PrintFakeBoard() {
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf("| X | X | X |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("|   |   |   |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("|   |   | O |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf("|   |   | X |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("|   | O |   |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("|   |   |   |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf("| O |   | X |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("| O |   |   |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf("| O |   |   |");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(NEW_LINE_CHAR);

	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
	printf(".___.___.___.");
	printf(UI_FAKEBOARD_SEPARATOR);
}

static void PrintMainMenu() {
	PrintHeader();

	printf(NEW_LINE_CHAR);
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

    int counter = SCORE_Get(playerInfoArray);
    printf("Tamanho Score: %d", counter);
    printf(NEW_LINE_CHAR);

    for(int i = 0; i < (counter-1); i++) {
        printf("%s\t%s\t%d%s", playerInfoArray[i].name, "3x3x3"/*playerInfoArray[i].name*/, playerInfoArray[i].score, NEW_LINE_CHAR);
        playerInfoArray[i];
    }

	printf(NEW_LINE_CHAR);
	puts(STRING_BACK_OPTION);
}

static void HandleMainMenu() {
	int option = UIGENERAL_GetUserOption(MAINMENU_MIN_OPTION, MAINMENU_MAX_OPTION);

	if(option == MAINMENU_PLAY) {
		PrintGameModeSubMenu();
		HandleGameModeSubMenu();
	} else if(option == MAINMENU_RANKING) {
		PrintRanking();
		HandleRanking();
	} else if(option == MAINMENU_QUIT) {
		exit(0);
	}
}

static void HandleGameModeSubMenu() {
	int option = UIGENERAL_GetUserOption(GAMEMENU_MIN_OPTION, GAMEMENU_MAX_OPTION);

	if(option == GAMEMENU_BOARD3D) {
		UIBOARD3D_Start();
	} else if(option == GAMEMENU_BOARD4D) {
		//UIBOARD4D_Start
	}
}

static void HandleRanking() {
	UIGENERAL_GetUserOption(BACK_OPTION, BACK_OPTION);
}
