/* Sushant Gupta */

#include "GameLib.h"

FILE *OpenAwardFile(int argc, char *argv[])
{
	char filename[20];
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

int FillAwardArray(FILE *readFH, AWARD AwardArray[MAX_ENTRIES])
{
	//lines of statements is stored in fileLine and entryCount stores number of entries in the game 
	char fileLine[100];
	int entryCount = 0;
	//each lines are read and stored in fileLine and entries is restricted to MAX_ENTRIES
	while((fgets(fileLine, 100, readFH) != NULL) && (entryCount < MAX_ENTRIES))
	{
		fileLine[strlen(fileLine) - 1] = '\0';
		//year is extracted from each line and stored in a variable
		char *token = strtok(fileLine, "|");
		strcpy(AwardArray[entryCount].year, token);
		//category is extracted from each line and stored in a variable
		token = strtok(NULL, "|");
		//memory is allocated for category element of AwardArray
		AwardArray[entryCount].category = malloc(strlen(token) * sizeof(char));
		strcpy(AwardArray[entryCount].category, token);
		//winner is extracted from each line and stored in a variable
		token = strtok(NULL, "|");
		//memory is allocated for winner element of AwardArray
		AwardArray[entryCount].winner = malloc(strlen(token) * sizeof(char));
		strcpy(AwardArray[entryCount].winner, token);
		//entryCount is increased
		entryCount++;
	}
	//opened file handle is closed
	fclose(readFH);
	//number of entries is returned to main
	return entryCount;
}

int PrintAwardMenu(AWARD AwardArray[MAX_ENTRIES], int entryCount)
{
	//the game menu is printed
	int i;
	printf("0. Exit\n");
	for(i = 1; i <= entryCount; i++)
	{
		printf("\n%d. %s %s\n", i, AwardArray[i-1].year, AwardArray[i-1].category);
	}
	//user is asked enter a selection number and it is protected to be within the given range in menu
	int choice = -1;
	while(choice < 0 || choice > entryCount)
	{
		printf("\n\nPick one choice for the game. Enter number from 0-%d: ", entryCount);
		scanf("%d", &choice);
		getchar();
	}
	//user selection is returned to main
	return choice;
}

void GuessIt(AWARD *AwardArray)
{
	//random number is generated for number of guesses
	srand(time(NULL));
	int randNum = rand();
	int winLenght = strlen(AwardArray->winner)/2;
	int guessNum = (randNum % winLenght) + 3;
	printf("\nYou get %d number of guesses.\n\n", guessNum);
	//copies of winner phrase are made
	char cpy1[strlen(AwardArray->winner)];
	strcpy(cpy1, AwardArray->winner);
	char cpy2[strlen(AwardArray->winner)];
	strcpy(cpy2, AwardArray->winner);
	//copy 1 is uppercased
	int j;
	for(j = 0; j<= (strlen(cpy1)-1); j++)
	{
		cpy1[j] = toupper(cpy1[j]);
	}
	//all the alphabets in copy 2 are replaced with -
	char *firstOccur = strpbrk(cpy2, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	while(firstOccur != NULL)
	{
		*firstOccur = '-';
		firstOccur = strpbrk(cpy2, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}
	printf("\n\n%s category in %s\n\n", AwardArray->category, AwardArray->year);
	char userGuess;
	char *guessMatch = NULL;
	char char2replace;
	int dist;
	//run the loop to allow user guess letters until guessNum is 0
	while(guessNum != 0)
	{
		//print the dashed or filled copy 2
		printf("%s\n", cpy2);
		//promt and ask user to enter guess letter
		printf("\n\nGuess a letter: ");
		scanf(" %c", &userGuess);
		//uppercasing the guess letter
		userGuess = toupper(userGuess);
		//checking if the copy 1 has the user guessed letter in it
		guessMatch = strchr(cpy1, userGuess);
		if(guessMatch == NULL)
		{
			//decreasing the guessNum with every wrong guess
			guessNum = guessNum -1;
			printf("\nSorry, your guess is incorrect. You have %d guesses left.\n", guessNum);
			if(guessNum == 0)
			{
			printf("\nYou are out of guesses now. Try again.\n\n");
			}
		}
		else
		{
			//all the correct answer is replaced in copy 2 and that place in copy 1 is replaced by -
			while(guessMatch != NULL)
			{
				*guessMatch = '-';
				dist = guessMatch - (&cpy1[0]);
				char2replace = (AwardArray->winner)[dist];
				cpy2[dist] = char2replace;
				guessMatch = strchr(cpy1, userGuess);
			}
		}
		//when player guessed all the letters correctly, the loop break and continue from begining
		if(strcmp(cpy2, AwardArray->winner) == 0)
		{
			printf("\n\nConratulations! You correctly guessed the winner.\n\n");
			printf("The winner of the %s %s was \"%s\"\n\n", AwardArray->year, AwardArray->category, AwardArray->winner);
			break;
		}
	}
}
