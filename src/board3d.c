/*
 ============================================================================
 Name        : board3d.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Constants
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <board3d.h>

const int playerSumsForScoring[] = {
	3,
	6
};
static int gameBoard[BOARD3D_DIMENSIONS_SIZE][BOARD3D_LINE_SIZE][BOARD3D_COL_SIZE];
static bool_t gameBoardIsEmpty = TRUE;

/* Forward declarations */
static char GetPositionChar(int dimension, int line, int col);
static void PutPlayerScore(int* playersScore, int resultSum);
static PlayerIds DefineWinningPlayer(int* playersScore);
static int Sum2dLines(int dimension, int line);
static int Sum2dCols(int dimension, int col);
static int Sum2dDiagonals(int dimension);
static int Sum2dInvertedDiagonals(int dimension);
static int Sum3dVerticalLines(int line, int col);
static int Sum3dExternalDiagonals(int line, int col);
static int Sum3dExternalInvertedDiagonals(int line, int col);
static int Sum3dInternalDiagonals(int line, int col);

/* Public functions */
void BOARD3D_Init() {
	memset(gameBoard, GAME_BOARD_ELEMENT_EMPTY_VALUE, sizeof(gameBoard));
	gameBoardIsEmpty = TRUE;
}
bool_t BOARD3D_GameBoardIsEmpty(void) {
	return gameBoardIsEmpty;
}

char BOARD3D_GetPositionChar(int dimension, int line, int col) {
	switch(gameBoard[dimension][line][col]) {
		case PLAYER_1:
			return playerSymbols[PLAYER_1];
		case PLAYER_2:
			return playerSymbols[PLAYER_2];
		default:
			return playerSymbols[NONE];
	}
}

void BOARD3D_MakeAMove(PlayerIds playerId, int dimension, int line, int col) {
	if(gameBoard[dimension][line][col] == GAME_BOARD_ELEMENT_EMPTY_VALUE) {
		gameBoard[dimension][line][col] = playerId;
	}

	if(gameBoardIsEmpty) {
		gameBoardIsEmpty = FALSE;
	}
}
bool_t BOARD3D_CheckEndGame() {
	for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
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
PlayerIds BOARD3D_CheckWinner() {
	int playersScore[BOARD3D_NUMBER_OF_PLAYERS];

	/* Check 2D lines(9 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			PutPlayerScore(playersScore, Sum2dLines(i, j));
		}
	}

	/* Check 2D columns(9 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			PutPlayerScore(playersScore, Sum2dCols(i, k));
		}
	}

	/* Check 2D diagonals(6 situations) */
	for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		PutPlayerScore(playersScore, Sum2dDiagonals(i));
		PutPlayerScore(playersScore, Sum2dInvertedDiagonals(i));
	}

	/* Check 3D vertical lines(9 situations) */
	for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			PutPlayerScore(playersScore, Sum3dVerticalLines(j, k));
		}
	}

	/* Check 3D external diagonals(4 situations) */
	PutPlayerScore(playersScore, Sum3dExternalDiagonals(0, 0));
	PutPlayerScore(playersScore, Sum3dExternalDiagonals(0, BOARD3D_COL_MAX_INDEX));
	PutPlayerScore(playersScore, Sum3dExternalDiagonals(BOARD3D_LINE_MAX_INDEX, 0));
	PutPlayerScore(playersScore, Sum3dExternalDiagonals(BOARD3D_LINE_MAX_INDEX, BOARD3D_COL_MAX_INDEX));

	/* Check 3D external inverted diagonals(4 situations) */
	PutPlayerScore(playersScore, Sum3dExternalInvertedDiagonals(0, 0));
	PutPlayerScore(playersScore, Sum3dExternalInvertedDiagonals(0, BOARD3D_COL_MAX_INDEX));
	PutPlayerScore(playersScore, Sum3dExternalInvertedDiagonals(BOARD3D_LINE_MAX_INDEX, 0));
	PutPlayerScore(playersScore, Sum3dExternalInvertedDiagonals(BOARD3D_LINE_MAX_INDEX, BOARD3D_COL_MAX_INDEX));

	/* Check 3D internal diagonals(4 situations) */
	PutPlayerScore(playersScore, Sum3dInternalDiagonals(0, 0));
	PutPlayerScore(playersScore, Sum3dInternalDiagonals(0, BOARD3D_COL_MAX_INDEX));
	PutPlayerScore(playersScore, Sum3dInternalDiagonals(BOARD3D_LINE_MAX_INDEX, 0));
	PutPlayerScore(playersScore, Sum3dInternalDiagonals(BOARD3D_LINE_MAX_INDEX, BOARD3D_COL_MAX_INDEX));

	return DefineWinningPlayer(playersScore);
}

/* Private functions */
static void PutPlayerScore(int* playersScore, int resultSum) {
	if(resultSum == playerSumsForScoring[PLAYER_1]) {
		playersScore[PLAYER_1]++;
	} else if(resultSum == playerSumsForScoring[PLAYER_2]) {
		playersScore[PLAYER_2]++;
	}
}
static PlayerIds DefineWinningPlayer(int* playersScore) {
	if(playersScore[PLAYER_1] > playersScore[PLAYER_2]) {
		return PLAYER_1;
	} else if(playersScore[PLAYER_2] > playersScore[PLAYER_1]) {
		return PLAYER_2;
	} else {
		/* Draw situation */
		return 0;
	}
}
static int Sum2dLines(int dimension, int line) {
	int lineSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		lineSum += gameBoard[dimension][line][k];
	}

	return lineSum;
}
static int Sum2dCols(int dimension, int col) {
	int colSum = 0;

	for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
		colSum += gameBoard[dimension][j][col];
	}

	return colSum;
}
static int Sum2dDiagonals(int dimension) {
	int diagSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int lineIndex = k;
		diagSum += gameBoard[dimension][lineIndex][k];
	}

	return diagSum;
}
static int Sum2dInvertedDiagonals(int dimension) {
	int invertedDiagSum = 0;

	for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
		int lineIndex = BOARD3D_COL_MAX_INDEX - k;
		invertedDiagSum += gameBoard[dimension][lineIndex][k];
	}

	return invertedDiagSum;
}
static int Sum3dVerticalLines(int line, int col) {
	int sumVerticalLines = 0;

	for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
		sumVerticalLines += gameBoard[i][line][col];
	}

	return sumVerticalLines;
}
static int Sum3dExternalDiagonals(int line, int col) {
	int diagSum = 0;

	if(line == 0 && col == 0) {		//iterate in lines
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			int dimensionIndex = j;
			diagSum += gameBoard[dimensionIndex][j][col];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == BOARD3D_COL_MAX_INDEX) {		//backward iterate in lines
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - j);
			diagSum += gameBoard[dimensionIndex][j][col];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == 0) {		//iterate in columns
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			int dimensionIndex = k;
			diagSum += gameBoard[dimensionIndex][line][k];
		}
	} else if(line == 0 && col == BOARD3D_COL_MAX_INDEX) {		//backward iterate in columns
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - k);
			diagSum += gameBoard[dimensionIndex][line][k];
		}
	}

	return diagSum;
}
static int Sum3dExternalInvertedDiagonals(int line, int col) {
	int invertedDiagSum = 0;

	if(line == 0 && col == 0) {		//iterate in columns
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			int dimensionIndex = k;
			invertedDiagSum += gameBoard[dimensionIndex][line][k];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == BOARD3D_COL_MAX_INDEX) {		//backward iterate in columns
		for(int k = 0; k < BOARD3D_COL_SIZE; k++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - k);
			invertedDiagSum += gameBoard[dimensionIndex][line][k];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == 0) {		//backward iterate in lines
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - j);
			invertedDiagSum += gameBoard[dimensionIndex][j][col];
		}
	} else if(line == 0 && col == BOARD3D_COL_MAX_INDEX) {		//iterate in lines
		for(int j = 0; j < BOARD3D_LINE_SIZE; j++) {
			int dimensionIndex = j;
			invertedDiagSum += gameBoard[dimensionIndex][j][col];
		}
	}

	return invertedDiagSum;
}
static int Sum3dInternalDiagonals(int line, int col) {
	int diagSum = 0;

	if(line == 0 && col == 0) {		//forward iterate in boards
		for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
			int dimensionIndex = i;
			int colIndex = i;
			diagSum += gameBoard[dimensionIndex][i][colIndex];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == BOARD3D_COL_MAX_INDEX) {		//backward iterate in boards
		for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - i);
			int colIndex = i;
			diagSum += gameBoard[dimensionIndex][i][colIndex];
		}
	} else if(line == BOARD3D_LINE_MAX_INDEX && col == 0) {		//backward iterate in boards
		for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
			int dimensionIndex = (BOARD3D_DIMENSIONS_MAX_INDEX - i);
			int colIndex = (BOARD3D_COL_MAX_INDEX - i);
			diagSum += gameBoard[dimensionIndex][i][colIndex];
		}
	} else if(line == 0 && col == BOARD3D_COL_MAX_INDEX) {		//forward iterate in boards
		for(int i = 0; i < BOARD3D_DIMENSIONS_SIZE; i++) {
			int dimensionIndex = i;
			int colIndex = (BOARD3D_COL_MAX_INDEX - i);
			diagSum += gameBoard[dimensionIndex][i][colIndex];
		}
	}

	return diagSum;
}
