/*
 ============================================================================
 Name        : score.h
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Functions to manage Score
 ============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SCORE_H
#define __SCORE_H

#include <constants.h>

#define SCORE_MAX_PLAYERS   256
#define SCORE_FILE_NAME     "score.txt"

/* Public functions */
void SCORE_Save(PlayerInfo* pPlayerInfo);
int SCORE_Get(PlayerInfo* playerInfoArray);

#endif /* __SCORE_H */
