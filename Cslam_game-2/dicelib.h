/* Sushant Gupta */

#ifndef DICELIB_H
#define DICELIB_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define numOfDice 5

#define numOfFace 6

void RollDice(int dice[]);

void PrintRoll(int dice[]);

void CountFaces(int dice[], int faceCount[]);

void FaceCombination(int faceCount[], char comMessage[]);

#endif
