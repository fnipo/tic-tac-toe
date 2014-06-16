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

#ifdef __unix__
#define NEW_LINE_CHAR		"\n"
#define CLEAR_COMMAND		"clear"
#elif defined(_WIN32) || defined(WIN32)
#define NEW_LINE_CHAR		"\n\r"
#define CLEAR_COMMAND		"cls"
#endif

#define GAME_BOARD_ELEMENT_EMPTY_VALUE		0

typedef int bool_t;
typedef enum { FALSE, TRUE };

typedef enum PlayerIds {
	NONE = 0,
	PLAYER_1 = 1,
	PLAYER_2 = 2
} PlayerIds;

extern const char playerSymbols[];

#endif /* __CONSTANTS_H */
