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
#define PLAYER_NAME_SIZE					256
#define MAINMENU_MIN_OPTION					1
#define MAINMENU_MAX_OPTION					3
#define GAMEMENU_MIN_OPTION					0
#define GAMEMENU_MAX_OPTION					2
#define BACK_OPTION							0
#define BOARD3D_PLAYER_MOVE_MIN_OPTION		1
#define BOARD3D_PLAYER_MOVE_MAX_OPTION		3

typedef int bool_t;
typedef enum { FALSE, TRUE };

typedef enum PlayerIds {
	NONE = 0,
	PLAYER_1 = 1,
	PLAYER_2 = 2
} PlayerIds;

typedef enum GameMode {
	BOARD_3D,
	BOARD_4D
} GameMode;

typedef enum MainMenuOption {
	MAINMENU_PLAY = 1,
	MAINMENU_RANKING = 2,
	MAINMENU_QUIT = 3
} MainMenuOption;

typedef enum GameModeMenuOption {
	GAMEMENU_BOARD3D = 1,
	GAMEMENU_BOARD4D = 2
} GameModeMenuOption;

typedef struct PlayerInfo {
    PlayerIds playerId;
	char name[PLAYER_NAME_SIZE];
	GameMode mode;
	int score;
} PlayerInfo;

extern const char playerSymbols[];

#endif /* __CONSTANTS_H */
