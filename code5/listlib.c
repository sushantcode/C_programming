/* Sushant Gupta */

#include "DrawTool.h"
#include "ListLib.h"

//function to add nodes in the linked list
void addNode(char dLetter, char *dCommand, node **LLH)
{
	//declaring temp ptr and new nodes
	node *TempPtr, *NewNode;
	//allocating memory for new node
	NewNode = malloc(sizeof(node));
	//allocating memory and size for draw command
	NewNode->drawCommand = malloc(strlen(dCommand)*sizeof(char));
	//filling new nodes from file lines
	NewNode->drawLetter = dLetter;
	strcpy(NewNode->drawCommand, dCommand);
	NewNode->nextPtr = NULL;
	//assigning temp ptr to linked list head
	TempPtr = *LLH;
	/* Linked list is empty so point head at new node */
	if (*LLH == NULL)
	{
		*LLH = NewNode;
	}
	else
	{
		TempPtr = *LLH;
		/* Traverse the linked list to find the end node */
		while (TempPtr->nextPtr != NULL)
		{
			TempPtr = TempPtr->nextPtr;
		}
		/* Change end node to point to new node*/
		TempPtr->nextPtr = NewNode;
	}
}

//function to search node with same letter as user input
void search_node(char userInput, char array[MAX_SIZE][MAX_SIZE], node **LLH, int letterCount)
{
	//checking the linked list
	node *TemPtr = *LLH;
	if(TemPtr == NULL)
	{
		printf("\nLinked List is empty\n");
	}
	while(TemPtr != NULL)
	{
		if(TemPtr->drawLetter == userInput)
		{
			char dCommand[strlen(TemPtr->drawCommand)];
			//making copy of the draw command
			strcpy(dCommand, TemPtr->drawCommand);
			//calling draw function to draw as per command when letter is matched
			drawFunction(dCommand, array, letterCount);
		}
		TemPtr = TemPtr->nextPtr;
	}
}
