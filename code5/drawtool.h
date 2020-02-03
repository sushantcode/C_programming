/* Sushant Gupta */

/* This file conatins all includes and prototypes of function */

#ifndef _DRAWTOOL_H
#define _DRAWTOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 20

void map(char array[MAX_SIZE][MAX_SIZE]);

void printMap(char array[MAX_SIZE][MAX_SIZE]);

void drawLine(char array[MAX_SIZE][MAX_SIZE], int row, int col, char command, int numSpot, char character);

void drawFunction(char *commandDraw, char array[MAX_SIZE][MAX_SIZE], int letterCount);

#endif
