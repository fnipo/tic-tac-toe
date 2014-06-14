/*
 ============================================================================
 Name        : 3dBoard.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Constants
 ============================================================================
 */

#include <3dBoard.h>
#include <constants.h>

int gameBoard[BOARD3D_DIMENSIONS][BOARD3D_LINE_SIZE][BOARD3D_COL_SIZE];

void init() {
	memset(gameBoard, GAME_BOARD_ELEMENT_EMPTY_VALUE, sizeof(gameBoard));
}

void printBoard(void) {
	//TODO
}

void makeAMove(PlayerIds playerId, int dimension, int line, int col) {
	if(gameBoard[dimension][line][col] == GAME_BOARD_ELEMENT_EMPTY_VALUE) {
		gameBoard[dimension][line][col] = playerId;
	}
}

bool_t checkEndGame() {
	for(int i = 0; i < BOARD3D_DIMENSIONS; i++) {
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
				if(gameBoard[i][j][k] == GAME_BOARD_ELEMENT_EMPTY_VALUE) {
					return FALSE;
				}
			}
		}
	}

	return TRUE;
}

PlayerIds checkWinner() {
	int playersScore[BOARD3D_NUMBER_OF_PLAYERS];

	/* Check 2D lines(9 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS; i++) {
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			putPlayerScore(sum2dLines(i, j));
		}
	}

	/* Check 2D columns(9 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS; i++) {
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			putPlayerScore(sum2dCols(i, k));
		}
	}

	/* Check 2D diagonals(6 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS; i++) {
		putPlayerScore(sum2dDiagonals(i));
		putPlayerScore(sum2dInvertedDiagonals(i));
	}

	/* Check 3D vertical lines(9 situations) */
	for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			putPlayerScore(sum3dVerticalLines(j, k));
		}
	}

	/* Check 3D external diagonals(8 situations) */
	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int maxLineIndex = BOARD3D_LINE_SIZE - 1;

		putPlayerScore(sum3dDiagonals(0, k));
		putPlayerScore(sum3dDiagonals(maxLineIndex, k));
	}

	/* Check 3D internal diagonals(2 situations) */

	return defineWinningPlayer();
}

static void putPlayerScore(int* playersScore, int resultSum) {
	switch(resultSum) {
		case(playerSumsForScoring[PLAYER_1]):
			playersScore[PLAYER_1]++;
			break;
		case(playerSumsForScoring[PLAYER_2]):
			playersScore[PLAYER_2]++;
			break;
		default:
			break;
	}
}

static PlayerIds defineWinningPlayer(int* playersScore) {
	if(playersScore[PLAYER_1] > playersScore[PLAYER_2]) {
		return PLAYER_1;
	} else if(playersScore[PLAYER_2] > playersScore[PLAYER_1]) {
		return PLAYER_2;
	} else {
		/* Draw situation */
		return 0;
	}
}

static int sum2dLines(int dimension, int line) {
	int lineSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		lineSum += gameBoard[dimension][line][k];
	}

	return lineSum;
}

static int sum2dCols(int dimension, int col) {
	int colSum = 0;

	for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
		colSum += gameBoard[dimension][j][col];
	}

	return colSum;
}

static int sum2dDiagonals(int dimension) {
	int diagSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int lineIndex = k;
		diagSum += gameBoard[dimension][lineIndex][k];
	}

	return diagSum;
}

static int sum2dInvertedDiagonals(int dimension) {
	int invertedDiagSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int maxColIndex = BOARD3D_COL_SIZE - 1;
		int lineIndex = maxColIndex - k;
		invertedDiagSum += gameBoard[dimension][lineIndex][k];
	}

	return invertedDiagSum;
}

static int sum3dVerticalLines(int line, int col) {
	int sumVerticalLines = 0;

	for(int i = 0; i < BOARD3D_DIMENSIONS; i++) {
		sumVerticalLines += gameBoard[i][line][col];
	}

	return sumVerticalLines;
}

static int sum3dDiagonals(int line, int col) {
	int diagSum = 0;

	for(int x = 0; x < BOARD3D_COL_SIZE; x++) {
		diagSum += gameBoard[dimension][x][x];
	}

	return diagSum;
}

static int sum3dInvertedDiagonals(int line, int col) {
	int invertedDiagSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int maxColIndex = BOARD3D_COL_SIZE - 1;
		int lineIndex = maxColIndex - k;
		invertedDiagSum += gameBoard[dimension][lineIndex][k];
	}

	return invertedDiagSum;
}
