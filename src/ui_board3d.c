/*
 ============================================================================
 Name        : ui_board3d.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : UI to Board3D module
 ============================================================================
 */

/* Includes */
#include <ui_board3d.h>
#include <constants.h>
#include <board3d.h>

static void PrintBoard(void);
static void PrintRequestPlayerName(void);
static void PrintRequestPlayerMove(void);

void UIBOARD3D_Start() {
	BOARD3D_Init();

	PlayerInfo player1;
	PrintRequestPlayerName(player1.name);
	player1.mode = BOARD_3D;

	PlayerInfo player2;
	PrintRequestPlayerName(player2.name);
	player2.mode = BOARD_3D;

	while(!BOARD3D_CheckEndGame()) {
		PrintBoard();
		puts(NEW_LINE_CHAR);
		PrintRequestPlayerMove();
	}

	/*
	 * TODO: 	Get and Set Score in PlayerInfo
	 * 			Save in Ranking
	 */
	switch(BOARD3D_CheckWinner()) {
		case PLAYER_1:
			break;
		case PLAYER_2:
			break;
	}
}

static void PrintRequestPlayerName(char* pName) {
	//TODO
}

static void PrintRequestPlayerMove(void) {
	//TODO
}

static void PrintBoard(void) {
	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %c | %c | %c |", BOARD3D_GetPositionChar(i,0,0), BOARD3D_GetPositionChar(i,0,1), BOARD3D_GetPositionChar(i,0,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %c | %c | %c |", BOARD3D_GetPositionChar(i,1,0), BOARD3D_GetPositionChar(i,1,1), BOARD3D_GetPositionChar(i,1,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %c | %c | %c |", BOARD3D_GetPositionChar(i,2,0), BOARD3D_GetPositionChar(i,2,1), BOARD3D_GetPositionChar(i,2,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);
}
