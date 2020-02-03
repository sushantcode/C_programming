/* Sushant Gupta */

/* This file contains the includes, struct types, and all the prototyping */
#ifndef _GAMELIB_H
#define _GAMELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 15

typedef struct
{
	char year[4];
	char *category;
	char *winner;
} AWARD;

FILE *OpenAwardFile(int argc, char *argv[]);

int FillAwardArray(FILE *readFH, AWARD AwardArray[MAX_ENTRIES]);

int PrintAwardMenu(AWARD AwardArray[MAX_ENTRIES], int entryCount);

void GuessIt(AWARD *AwardArray);

#endif
