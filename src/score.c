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
#include <stdlib.h>
#include <strings.h>

void SCORE_Save(PlayerInfo* pPlayerInfo) {
    FILE* pFile;
    pFile = fopen(SCORE_FILE_NAME, "a+");
    if(pFile != NULL) {
        fprintf(pFile, "%s", pPlayerInfo->name);
        switch(pPlayerInfo->mode) {
            case BOARD_3D:
                fprintf(pFile, ",%s", STRING_GAMEMODE_BOARD3D_NAME);
                break;
            case BOARD_4D:
                fprintf(pFile, ",%s", STRING_GAMEMODE_BOARD4D_NAME);
                break;
        }
        fprintf(pFile, ",%d", pPlayerInfo->score);
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
            char* gameMode;
            char endLine;
            fscanf(pFile, "%s[^,],%s[^,],%d", &(playerInfoArray[counter].name), gameMode
                   , &(playerInfoArray[counter].score));
            /*fscanf(pFile, "%s %s %d%c", &(playerInfoArray[counter].name), gameMode
                   , &(playerInfoArray[counter].score), &endLine);*/

            if(gameMode == STRING_GAMEMODE_BOARD3D_NAME) {
                playerInfoArray[counter].mode = BOARD_3D;
            } else if(gameMode == STRING_GAMEMODE_BOARD4D_NAME) {
                playerInfoArray[counter].mode = BOARD_4D;
            }

            counter++;
        }
        fclose(pFile);
        return counter;
    }
    else {
        puts(STRING_ERROR_SAVE_SCORE);
    }
}
