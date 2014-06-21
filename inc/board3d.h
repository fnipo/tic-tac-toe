/*
 ============================================================================
 Name        : board3d.h
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Constants
 ============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOARD_3D_H
#define __BOARD_3D_H

/* Includes */
#include <constants.h>

/* Defines */
#define BOARD3D_DIMENSIONS_SIZE			            3
#define BOARD3D_DIMENSIONS_MAX_INDEX	            (BOARD3D_DIMENSIONS_SIZE - 1)
#define BOARD3D_LINE_SIZE 				            3
#define BOARD3D_LINE_MAX_INDEX 			            (BOARD3D_LINE_SIZE - 1)
#define BOARD3D_COL_SIZE 				            3
#define BOARD3D_COL_MAX_INDEX			            (BOARD3D_COL_SIZE - 1)
#define BOARD3D_NUMBER_OF_PLAYERS		            2
#define BOARD3D_BASE_SCORE_POINT		            50
#define BOARD3D_2D_SCORE_MULTIPLIER		            1
#define BOARD3D_3D_NON_DIAGONAL_SCORE_MULTIPLIER    2
#define BOARD3D_3D_DIAGONAL_SCORE_MULTIPLIER		3
#define BOARD3D_UI_BOARDS_SEPARATOR		            "     "

extern const int playerSumsForScoring[];

/* Public functions */
void BOARD3D_Init();
bool_t BOARD3D_GameBoardIsEmpty(void);
char BOARD3D_GetPositionChar(int dimension, int line, int col);
int BOARD3D_GetPositionValue(int dimension, int line, int col);
void BOARD3D_MakeAMove(PlayerIds playerId, int dimension, int line, int col);
bool_t BOARD3D_CheckEndGame();
PlayerIds BOARD3D_CheckWinner();
int BOARD3D_GetScore(PlayerIds playerId);

#endif /* __BOARD_3D_H */
