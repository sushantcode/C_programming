/* Sushant Gupta */

/* This program rolls five dices and find the combination. */

//include the created header file
#include "DiceLib.h"

int main(void)
{
	char response = 'y';
	int numberOfReRolls;
	//declaring dice array as a variable
	int dice[numOfDice];
	//create loop to allow user to reroll as they wish
	while(response == 'y' || (response == 'Y'))
	{
		//call the functions
		RollDice(dice);
		printf("\nYou rolled");
		PrintRoll(dice);
		int faceCount[numOfFace] = {0, 0, 0, 0, 0, 0};
		CountFaces(dice, faceCount);
		char comMessage[20];
		FaceCombination(faceCount, comMessage);
		//print the combination result message
		printf("%s", comMessage);
		//check the number of rerolls and exit the loop if the conditon  is met
		if(numberOfReRolls == 2)
		{
			break;
		}
		printf("\nDo you want to Reroll? Enter 'y'/'Y' to Re-Roll or anything else to exit: ");
		scanf("   %c", &response);
		numberOfReRolls++;
	}
	//print the exiting message
	printf("\nThank you for playing this game. See You Again!!! \n\n");
	return 0;
}
