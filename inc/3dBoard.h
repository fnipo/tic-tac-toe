/*
 ============================================================================
 Name        : 3dBoard.h
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Constants
 ============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __3D_BOARD_H
#define __3D_BOARD_H

#define BOARD3D_DIMENSIONS_SIZE			3
#define BOARD3D_DIMENSIONS_MAX_INDEX	(BOARD3D_DIMENSIONS_SIZE - 1)
#define BOARD3D_LINE_SIZE 				3
#define BOARD3D_LINE_MAX_INDEX 			(BOARD3D_LINE_SIZE - 1)
#define BOARD3D_COL_SIZE 				3
#define BOARD3D_COL_MAX_INDEX			(BOARD3D_COL_SIZE - 1)

#define BOARD3D_NUMBER_OF_PLAYERS		2

const int playerSumsForScoring[] = {
	3,
	6
};

#endif /* __3D_BOARD_H */
