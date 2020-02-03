/* Sushant Gupta */

#include "DiceLib.h"

//function to just roll the dices and fill the dice array
void RollDice(int dice[])
{
	int i;
	srand(time(0));
	//storing random values from 1-6 in the dice array
	for(i = 0; i < numOfDice; i++)
	{
		dice[i] = (rand() % 6 ) + 1;
	}
	return;
}

//function to print the faces of the rolling dices
void PrintRoll(int dice[])
{
	int x;
	for(x = 0; x < numOfDice; x++)
	{
		printf(" %d", dice[x]);
	}
	return;
}

//function to count the number of faces
void CountFaces(int dice[], int faceCount[])
{
	int j;
	int l;
	for(j = 0; j < numOfFace; j++)
	{
		for(l = 0; l < numOfDice; l++)
		{
			if(dice[l] == j + 1)
			{
				faceCount[j]++;
			}
		}
	}
	return;
}
	
//function to find the combination and send it back to main function
void FaceCombination(int faceCount[], char comMessage[])
{
	//define and intialize the combination sets
	int twoPairs = 0;
	int fullHouse = 0;
	int threeOfaKind = 0;
	int fourOfaKind = 0;
	int smallStraight = 0;
	int largeStraight = 0;
	int cSlam = 0;
	//loop to check the frequency of faces in each roll and set certain values to each combination accordingly
	int k;
	for(k = 0; k < numOfFace; k++)
	{
		if(faceCount[k] == 3)
		{
			fullHouse = fullHouse + 3;
			threeOfaKind = threeOfaKind + 3;
		}
			
		if(faceCount[k] == 2)
		{
			twoPairs++;
			fullHouse = fullHouse + 2;
		}
		
		if(faceCount[k] == 5)
		{
			cSlam++;
		}
		
		if(faceCount[k] == 1)
		{
			largeStraight++;
		}
		else if((faceCount[k] == 0) && (largeStraight > 0) && (largeStraight < 5))
		{
			largeStraight = 0;
		}
			
		if(faceCount[k] >= 1)
		{
			smallStraight++;
		}
		else if((faceCount[k] == 0) && (smallStraight > 0) && (smallStraight < 4))
		{
			smallStraight = 0;
		}
			
		if(faceCount[k] == 4)
		{
			fourOfaKind++;
		}
	}
	//check and print the combination according to given condition
	if(cSlam == 1)
	{
		strcpy(comMessage,"\nCSlam!\n");
	}
	else if(largeStraight == 5)
	{
		strcpy(comMessage,"\nLarge Straight\n");
	}
	else if(smallStraight >= 4)
	{
		strcpy(comMessage,"\nSmall Straight\n");
	}
	else if(fullHouse == 5)
	{
		strcpy(comMessage,"\nFull House\n");
	}
	else if(fourOfaKind == 1)
	{
		strcpy(comMessage,"\nFour-of-a-Kind\n"); 
	}
	else if(threeOfaKind == 3)
	{
		strcpy(comMessage,"\nThree-of-a-Kind\n");
	}
	else if(twoPairs == 2)
	{
		strcpy(comMessage,"\nTwo Pairs\n");
	}
	else
	{
		strcpy(comMessage,"\nYou have nothing.\n");
	}
}
