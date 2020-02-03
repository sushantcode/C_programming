/* Sushant Gupta */

#ifndef _LISTLIB_H
#define _LISTLIB_H

typedef struct node
{
	char drawLetter;
	char *drawCommand;
	struct node *nextPtr;
}
node;

FILE *OpenFile(int argc, char *argv[]);

void addNode(char dLetter, char *dCommand, node **LLH);

void search_node(char userInput, char array[MAX_SIZE][MAX_SIZE], node **LLH, int letterCount);

#endif
