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
#include <strings.h>
#include <ui_general.h>

static void PrintBoard(void);
static void PrintRequestPlayerName(PlayerIds player, char* pName);
static void RequestPlayerMove(PlayerInfo* pPlayer);
static void PrintBoardDebugMode(void);
static void MakeFakeDebugMoves(void);

void UIBOARD3D_Start() {
	BOARD3D_Init();

    UTIL_ClearConsole();

	PlayerInfo player1;
	player1.playerId = PLAYER_1;
	PrintRequestPlayerName(PLAYER_1, player1.name);
	player1.mode = BOARD_3D;

	PlayerInfo player2;
	player2.playerId = PLAYER_2;
	PrintRequestPlayerName(PLAYER_2, player2.name);
	player2.mode = BOARD_3D;

    PlayerInfo* actualPlayer = &player1;

	while(!BOARD3D_CheckEndGame()) {
        UTIL_ClearConsole();
		PrintBoard();
		//PrintBoardDebugMode();
		puts(NEW_LINE_CHAR);
		RequestPlayerMove(actualPlayer);

		if(actualPlayer->playerId == PLAYER_1) {
            actualPlayer = &player2;
		} else {
		    actualPlayer = &player1;
		}
	}

    /* DEBUG */
    //MakeFakeDebugMoves();
    //PrintBoardDebugMode();

    printf(NEW_LINE_CHAR);
	switch(BOARD3D_CheckWinner()) {
		case PLAYER_1:
		    player1.score = BOARD3D_GetScore(PLAYER_1);
		    printf(NEW_LINE_CHAR);
		    printf("%s Win! Score: %d%s", player1.name, player1.score, NEW_LINE_CHAR);
		    SCORE_Save(&player1);
			break;
		case PLAYER_2:
		    player2.score = BOARD3D_GetScore(PLAYER_2);
		    printf(NEW_LINE_CHAR);
		    printf("%s Win! Score: %d%s", player2.name, player2.score, NEW_LINE_CHAR);
		    SCORE_Save(&player2);
			break;
	}

    printf(NEW_LINE_CHAR);
    puts("Press ENTER to exit");
    getchar();
    getchar();
}
static void PrintRequestPlayerName(PlayerIds player, char* pName) {
    switch(player) {
        case PLAYER_1:
            puts(STRING_REQUEST_PLAYER1_NAME);
            break;
        case PLAYER_2:
            puts(STRING_REQUEST_PLAYER2_NAME);
            break;
    }

    scanf("%s", pName);
}
static void RequestPlayerMove(PlayerInfo* pPlayer) {
    //TODO: If position is not empty?

	printf(STRING_REQUEST_PLAYER_MOVE_MASK, pPlayer->name);
	printf(NEW_LINE_CHAR);

	puts(STRING_REQUEST_3D_BOARD);
	int board = UIGENERAL_GetUserOption(BOARD3D_PLAYER_MOVE_MIN_OPTION, BOARD3D_PLAYER_MOVE_MAX_OPTION);

	puts(STRING_REQUEST_3D_LINE);
	int line = UIGENERAL_GetUserOption(BOARD3D_PLAYER_MOVE_MIN_OPTION, BOARD3D_PLAYER_MOVE_MAX_OPTION);

	puts(STRING_REQUEST_3D_COLUMN);
	int col = UIGENERAL_GetUserOption(BOARD3D_PLAYER_MOVE_MIN_OPTION, BOARD3D_PLAYER_MOVE_MAX_OPTION);

	BOARD3D_MakeAMove(pPlayer->playerId, (board-1), (line-1), (col-1));
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
static void PrintBoardDebugMode(void) {
    UTIL_ClearConsole();

    for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %d | %d | %d |", BOARD3D_GetPositionValue(i,0,0), BOARD3D_GetPositionValue(i,0,1), BOARD3D_GetPositionValue(i,0,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %d | %d | %d |", BOARD3D_GetPositionValue(i,1,0), BOARD3D_GetPositionValue(i,1,1), BOARD3D_GetPositionValue(i,1,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf("| %d | %d | %d |", BOARD3D_GetPositionValue(i,2,0), BOARD3D_GetPositionValue(i,2,1), BOARD3D_GetPositionValue(i,2,2));
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);

	for (int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		printf(".___.___.___.");
		printf(BOARD3D_UI_BOARDS_SEPARATOR);
	}
	printf(NEW_LINE_CHAR);
}
static void MakeFakeDebugMoves(void) {
    PlayerIds winner = PLAYER_1;
    //PlayerIds winner = PLAYER_2;
    PlayerIds loser = PLAYER_2;
    //PlayerIds loser = PLAYER_1;

    BOARD3D_MakeAMove(winner, 0, 0, 0);
    BOARD3D_MakeAMove(winner, 0, 0, 1);
    BOARD3D_MakeAMove(winner, 0, 0, 2);
    BOARD3D_MakeAMove(winner, 0, 1, 0);
    BOARD3D_MakeAMove(winner, 0, 2, 0);
    BOARD3D_MakeAMove(winner, 1, 0, 0);
    BOARD3D_MakeAMove(winner, 1, 0, 1);
    BOARD3D_MakeAMove(winner, 1, 1, 0);
    BOARD3D_MakeAMove(winner, 1, 1, 1);
    BOARD3D_MakeAMove(winner, 1, 2, 0);

    BOARD3D_MakeAMove(winner, 2, 0, 0);
    BOARD3D_MakeAMove(winner, 2, 0, 1);
    BOARD3D_MakeAMove(winner, 2, 1, 0);
    BOARD3D_MakeAMove(winner, 2, 2, 0);
    BOARD3D_MakeAMove(winner, 2, 2, 2);


    BOARD3D_MakeAMove(loser, 0, 1, 1);
    BOARD3D_MakeAMove(loser, 0, 1, 2);
    BOARD3D_MakeAMove(loser, 0, 2, 1);
    BOARD3D_MakeAMove(loser, 0, 2, 2);
    BOARD3D_MakeAMove(loser, 1, 0, 2);
    BOARD3D_MakeAMove(loser, 1, 1, 2);
    BOARD3D_MakeAMove(loser, 1, 2, 1);
    BOARD3D_MakeAMove(loser, 1, 2, 2);
    BOARD3D_MakeAMove(loser, 2, 0, 2);
    BOARD3D_MakeAMove(loser, 2, 1, 1);
    BOARD3D_MakeAMove(loser, 2, 1, 2);
    BOARD3D_MakeAMove(loser, 2, 2, 1);
}
