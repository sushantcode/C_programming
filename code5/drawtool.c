/* Sushant Gupta */

/*This files contains all necessary functions to draw*/

#include "DrawTool.h"
#include "ListLib.h"

//function to intialize the map to draw
void map(char array[MAX_SIZE][MAX_SIZE])
{
	printf("\nEnter the background character for the map: ");
	char backChar;
	scanf(" %c", &backChar);
	int i;
	int j;
	for(i = 0; i < MAX_SIZE; i++)
	{
		for(j = 0; j < MAX_SIZE; j++)
		{
			*(*(array + i) + j) = backChar;
		}
}
}

//function to print the map
void printMap(char array[MAX_SIZE][MAX_SIZE])
{
	int i;
	int j;
	printf("\n");
	for(i = 0; i < MAX_SIZE; i++)
	{
		printf("\n");
		for(j=0; j < MAX_SIZE; j++)
		{
			printf("%c  ", *(*(array + i) + j));
		}
	}
	printf("\n");
}

//function to draw lines in the map
void drawLine(char array[MAX_SIZE][MAX_SIZE], int row, int col, char command, int numSpot, char character)
{
	if(tolower(command) == 'v')
	{
		int i;
		for(i = 0; i < numSpot; i++)
		{
			*(*(array + (row + i)) + col) = character;
		}
	}
	else
	{
		int j;
		for(j = 0; j < numSpot; j++)
		{
			*(*(array + row) + (col + j)) = character;
		}
	}
}

//function to draw and update the map
void drawFunction(char *commandDraw, char array[MAX_SIZE][MAX_SIZE], int letterCount)
{
	//separating each character command from user input string
	char *delimiters = "(,)";
	char *commandStr = strtok(commandDraw, delimiters);
	char command = *commandStr;
	char *rowStr = strtok(NULL, delimiters);
	int row = atoi(rowStr);
	char *colStr = strtok(NULL, delimiters);
	int col = atoi(colStr) + letterCount;
	char *numSpotStr = strtok(NULL, delimiters);
	int numSpot = atoi(numSpotStr);
	char character;
	char *charStr = strtok(NULL, delimiters);
	//condition to check if user has entered character to draw or just set 'X' if not
	if(charStr == '\0')
	{
		character = 'X';
	}
	else
	{
		character = *charStr;
	}
	//checking if user entered numbers for row, column, and spot number to draw
	if(!isdigit(*rowStr) || !isdigit(*colStr) || !isdigit(*numSpotStr))
	{
		printf("That draw command is unknown.");
	}
	//checking if the row and column size are within range of user input size of array
	if((row >= 0 && row < MAX_SIZE) && (col >= 0 && col < MAX_SIZE) && (numSpot > 0 && numSpot <= MAX_SIZE))
	{
		//checking and marking a spot if use enter 'p'
		if(tolower(command) == 'p')
		{
			*(*(array + row) + col) = character;
		}
		//checking and calling functions to draw vertical and horizontal characters
		else if(tolower(command) == 'v' || tolower(command) == 'h')
		{
			if(tolower(command) == 'v' && (row + numSpot) > MAX_SIZE)
			{
				printf("That draw command is out of range.");
			}
			else if(tolower(command) == 'h' && (col + numSpot) > MAX_SIZE)
			{
				printf("That draw command is out of range.");
			}
			else
			{
				drawLine(array, row, col, command, numSpot, character);
			}
		}
		else
		{
			printf("That draw command is unknown.");
		}
	}
	else
	{
		printf("That draw command is out of range.");
	}
}
