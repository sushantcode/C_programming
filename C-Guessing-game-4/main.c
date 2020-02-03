/* This program is a computer version of hang-man game where player guess the name of Academy Award winner.*/

#include "GameLib.h"

int main(int argc, char *argv[])
{
	//defining the AwardArray with max entries size
	AWARD AwardArray[MAX_ENTRIES];
	//calling function to open file and get file handle of the given file
	FILE *readFH = OpenAwardFile(argc, argv);
	//calling function to fill the award array and get number of entries stored in the array
	int entryCount = FillAwardArray(readFH, AwardArray);
	printf("\n\nWelcome to Guessing the Academy Award's Winner game!!!\n\n");
	//declaring and initializing user choice to -1 so that game stop when user enter 0
	int choice = -1;
	while(choice != 0)
	{
		//calling function to print the menu promting the instruction and user choices and store user selection in choice var
		choice = PrintAwardMenu(AwardArray, entryCount);
		if(choice != 0)
		{
			//calling function to check and print the game result
			GuessIt(&AwardArray[choice - 1]);
		}
	}
	printf("\n\nThank You for playing this game. See You Again!!!\n\n");
	int i;
	//freeing up the malloc memory
	for(i = 0; i < entryCount; i++)
	{
		free(AwardArray[i].category);
		free(AwardArray[i].winner);
	}
	return 0;
}
