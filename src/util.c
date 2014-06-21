/*
 ============================================================================
 Name        : util.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Common functions
 ============================================================================
 */

/* Includes */
#include <util.h>
#include <constants.h>
#include <stdio.h>
#include <stdlib.h>

void UTIL_ClearConsole() {
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system(CLEAR_COMMAND);
}
