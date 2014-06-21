/*
 ============================================================================
 Name        : score.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Functions to manage Score
 ============================================================================
 */
/* Includes */
#include <score.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

static char fileLine[SCORE_FILE_LINE_MAX_LENGTH];

/* Private Functions */
static int GetScoreLength(void);
static void ClearScore(void);

/* Public Functions */
void SCORE_Save(PlayerInfo* pPlayerInfo) {
    if(GetScoreLength() >= SCORE_MAX_PLAYERS) {
        ClearScore();
    }

    FILE* pFile;
    pFile = fopen(SCORE_FILE_NAME, "a+");

    if(pFile != NULL) {
        fprintf(pFile, "%s", pPlayerInfo->name);
        switch(pPlayerInfo->mode) {
            case BOARD_3D:
                fprintf(pFile, "%s%s", SCORE_DATA_STR_SEPARATOR, STRING_GAMEMODE_BOARD3D_NAME);
                break;
            case BOARD_4D:
                fprintf(pFile, "%s%s", SCORE_DATA_STR_SEPARATOR, STRING_GAMEMODE_BOARD4D_NAME);
                break;
        }
        fprintf(pFile, "%s%d", SCORE_DATA_STR_SEPARATOR, pPlayerInfo->score);
        fprintf(pFile, "\n");

        fclose(pFile);
    }
    else {
        puts(STRING_ERROR_SAVE_SCORE);
    }
}

int SCORE_Get(PlayerInfo* playerInfoArray) {
    FILE* pFile;
    pFile = fopen(SCORE_FILE_NAME, "r");
    int counter = 0;

    if(pFile != NULL) {
        while(!feof(pFile)) {
            fgets(fileLine, SCORE_FILE_LINE_MAX_LENGTH, pFile);

            char* tok = strtok(fileLine, SCORE_DATA_STR_SEPARATOR);
            snprintf(playerInfoArray[counter].name, strlen(tok) + 1, "%s", tok);

            tok = strtok(NULL, SCORE_DATA_STR_SEPARATOR);
            if(tok == STRING_GAMEMODE_BOARD3D_NAME) {
                playerInfoArray[counter].mode = BOARD_3D;
            } else if(tok == STRING_GAMEMODE_BOARD4D_NAME) {
                playerInfoArray[counter].mode = BOARD_4D;
            }

            tok = strtok(NULL, SCORE_DATA_STR_SEPARATOR);
            playerInfoArray[counter].score = atoi(tok);

            counter++;
            //memset(fileLine, 0, sizeof(fileLine));
        }
        fclose(pFile);
        return counter;
    }
    else {
        puts(STRING_ERROR_SAVE_SCORE);
    }
}

static int GetScoreLength(void) {
    FILE* pFile;
    pFile = fopen(SCORE_FILE_NAME, "r");
    int counter = 0;

    if(pFile != NULL) {
        while(!feof(pFile)) {
            fgets(fileLine, SCORE_FILE_LINE_MAX_LENGTH, pFile);
            counter++;
        }
        fclose(pFile);
        return counter;
    }
    else {
        puts(STRING_ERROR_SAVE_SCORE);
    }
}

static void ClearScore(void) {
    remove(SCORE_FILE_NAME);
}
