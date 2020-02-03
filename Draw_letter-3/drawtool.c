/* Sushant Gupta */

/*This files contains all necessary functions to draw*/

#include "DrawTool.h"

//function to intialize the map to draw
void map(char array[MAX_SIZE][MAX_SIZE], int *mapSize)
{
	while(*mapSize < 1 || *mapSize > MAX_SIZE)
	{
		printf("What size of map you want? Enter a number between 1 and %d: ", MAX_SIZE);
		scanf("%d", mapSize);
		getchar();
	}
	printf("Enter the background character for the map: ");
	char backChar;
	scanf(" %c", &backChar);
	int i;
	int j;
	for(i = 0; i < *mapSize; i++)
	{
		for(j = 0; j < *mapSize; j++)
		{
			*(*(array + i) + j) = backChar;
		}
	}
}

//function to print the instructions set on how to user the tool
void printInstrutions()
{
	getchar();
	printf("\nDraw commands start with \n\n\tP for a single point\n\tH for a horizontal line\n\tV for a vertical line\n\nAfter the P/V/H, enter a row,col coordinate and the number of spots to mark\nenclosed in () and separated by commas and then the character for the mark.\n'X' will be used if a mark is not entered. For example,\n\n\tP(2,3,1)*\t start at point 2,3 in the array and mark one spot\n\t         \t with an *. For P, the 3rd parameter is ignored.\n\n\tV(1,2,3)$\t start at point 1,2 in the array and mark the next\n\t         \t 3 spots down from the current position with $\n\n\tH(4,6,7)#\t start at point 4,6 in the array and mark the next\n\t         \t 7 spots to the right with #\n\nCoordinates out of range and lines drawn past the borders are not allowed.\n\nEnter Q at the draw command prompt to quit\n\n");
	printf("Press <ENTER> to continue ");
	getchar();
}

//function to print the map
void printMap(char array[MAX_SIZE][MAX_SIZE], int *mapSize)
{
	int i;
	int j;
	printf("\n");
	for(i = 0; i < *mapSize; i++)
	{
		printf("\n");
		for(j=0; j < *mapSize; j++)
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
