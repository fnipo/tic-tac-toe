/*
 ============================================================================
 Name        : constants.h
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Constants
 ============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CONSTANTS_H
#define __CONSTANTS_H

#define GAME_BOARD_ELEMENT_EMPTY_VALUE		0

typedef int bool_t;
typedef enum { FALSE, TRUE };

typedef enum PlayerIds {
	PLAYER_1 = 1,
	PLAYER_2 = 2
} PlayerIds;

const char playerSymbols[] = {
	"X",
	"O"
};

#endif /* __CONSTANTS_H */
