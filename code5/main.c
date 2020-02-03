/* Sushant Gupta */

/* This program will print 3 letters on a map. */

#include "DrawTool.h"
#include "ListLib.h"

int main(int argc, char *argv[])
{
	//declaring linked list head
	node *LLH = NULL;
	//declaring array
	char array[MAX_SIZE][MAX_SIZE];
	//calling function to open file and get file handle of the given file
	FILE *readFH = OpenFile(argc, argv);
	//lines of statements is stored in fileLine
	char fileLine[100];
	//each lines are read and stored in fileLine
	while(fgets(fileLine, 100, readFH) != NULL)
	{
		//extracting first letter to draw
		char *dLetter = strtok(fileLine, "|");
		//extracting draw command from fileline
		char *dCommand = strtok(NULL, "|");
		//printf("%s\n", dCommand);
		addNode(*dLetter, dCommand, &LLH);
	}
	//closing file
	fclose(readFH);
	//calling map function to initialize it
	map(array);
	getchar();
	//declaring variable to store userinput
	char userInput[3];
	printf("\nEnter 1-3 letters to draw: ");
	//taking draw command from user
	scanf(" %s", userInput);
	//checking if the input has sufficient number of character
	while(strlen(userInput)<1 || strlen(userInput)>3)
	{
		printf("\nInvalid Input! Enter 1-3 letter(s) only: ");
		//taking draw command from user
		scanf(" %s", userInput);
	}
	int k = 0;
	//initializing variable to keep record of position of each alphabet
	int letterCount = 0;
	//looping to call search function for each letter from user
	while(userInput[k] != '\0')
	{
		//calling search node to find the letter and update map
		search_node(toupper(userInput[k]), array, &LLH, letterCount);
		//position increment
		letterCount = letterCount + 7;
		k++;
	}
	//printing final map
	printMap(array);
	return 0;
}

FILE *OpenFile(int argc, char *argv[])
{
	//initializing variable for file input
	char filename[30];
	//if command line contains 2 arguments, second one is copied to filename else user is asked to enter filename
	if(argc == 2)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		//promting user to enter filename
		printf("\nMust be run with an input file name.\nEnter the filename: ");
		scanf(" %s", &filename);
		getchar();
	}
	//file is opened with read only mode and stored in file handle
	FILE *readFH = fopen(filename, "r");
	//user is promted to enter new file if file is empty
	while(readFH == NULL)
	{
		printf("\nCould not open input file named %s.\nEnter the new filename: ", filename);
		scanf(" %s", &filename);
		getchar();
		readFH = fopen(filename, "r");
	}
	//file handle is returned
	return readFH;
}
