#include "common.h"

void dcp35_algo(char **inputArray);
void swapIndexValues(char **string, int index1, int index2);

enum {CHAR_R, CHAR_G, CHAR_B, CHAR_M};

static void problemDescription(void)
{
	printf(
			"\n"
			"\nGiven an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array."
			"\nDo this in linear time and in-place."
			"\nFor example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B']."
			"\n"
			);
}

static int problemOptions(void)
{
	printf(
			"\n"
			"\n0. Exit"
			"\n1. Use random array"
			"\n2. Enter array values"
			"\n3. Default array values"
			"\n"
			);
	return readInputInteger();
}

void dcp35(void)
{
	clearScreen();
	problemDescription();
	
	int choice = problemOptions();	
	if (choice == 0) return;

	char *inputArray = NULL;
	if (choice == 1)
	{
		printf("\nEnter number of random values: ");
		int numberOfValues = readInputInteger();
		if (numberOfValues <= 0) numberOfValues = 10;
		srand(time(NULL));
		inputArray = (char *)(calloc(numberOfValues, sizeof(char)));
		for (int i = 0; i < numberOfValues; i++)
		{
			int temp = rand() % 10;
			printf("\ntmp: %d", temp);
			if (temp < 3) inputArray[i] = 'R';
			else if (temp < 7) inputArray[i] = 'G';
			else inputArray[i] = 'B';
		}
	}
	else if (choice == 2)
	{
		inputArray = readInputString();
	}
	else if (choice == 3)
	{
		inputArray = (char *)(calloc(8, sizeof(char)));
		inputArray[0] = 'G';
		inputArray[1] = 'B';
		inputArray[2] = 'R';
		inputArray[3] = 'R';
		inputArray[4] = 'B';
		inputArray[5] = 'R';
		inputArray[6] = 'G';
	}


	if (inputArray)
	{
		dcp35_algo(&inputArray);
		free(inputArray);
	}
			
}

void dcp35_algo(char **inputArray)
{
	char *tmpStr = *inputArray;
	int length = strlen(tmpStr);

	int countIndex[CHAR_M] = {0, 0, 0};

	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c ", (*inputArray)[i]);
	}

	int currentIndex = 0;
	printf(
			"\n Approach: Increment the count of each character that we need to look for."
			"\n We would then know if we encounter an R, it should always go to index at: count(R)"
			"\n Similarly, if we encounter an G, it should always go to index at: count(R) + count(G)"
			"\n And, if we encounter an B, it should always go to index at: count(R) + count(G) + count(B)"
			"\n We make only one pass through the array, and swap elements in place, keep it O(n)"
			);
	while(currentIndex < length)
	{
		printf("\n");
		const char *colourValue = COLOUR_NONE;
		for (int i = 0; i < length; i++)
		{
			colourValue = COLOUR_NONE;
			if (i == currentIndex) colourValue = COLOUR_YELLOW; 
			printf("%s%c%s ", colourValue, (*inputArray)[i], COLOUR_NONE);
		}	
		printf("\tInitial:%s%3d %s%3d %s%3d%s", COLOUR_RED, countIndex[CHAR_R], COLOUR_GREEN, countIndex[CHAR_G], COLOUR_BLUE, countIndex[CHAR_B], COLOUR_NONE);
		
		switch((*inputArray)[currentIndex])
		{
			case 'R':
				countIndex[CHAR_R]++;
				break;
			case 'G':
				countIndex[CHAR_G]++;
				break;
			case 'B':
				countIndex[CHAR_B]++;
				break;
		}

		// If currentIndex = R, them it would always have to be at countIndex[CHAR_R]-1;
		// If currentIndex = G, them it would always have to be at countIndex[CHAR_R] + countIndex[CHAR_G] -1;
		// If currentIndex = B, them it would always have to be at countIndex[CHAR_R] + countIndex[CHAR_G] + countIndex[CHAR_B] -1;
		//
		int indexCount = 0;
		for (int i = 0; i < CHAR_M; i++)
		{
			indexCount += countIndex[i];
			if ( 
					(i == 0 && (*inputArray)[currentIndex] == 'R') ||
					(i == 1 && (*inputArray)[currentIndex] == 'G') ||
					(i == 2 && (*inputArray)[currentIndex] == 'B')
			   )
			{
				swapIndexValues(inputArray, indexCount - 1, currentIndex);
			}
		}

		printf("\tUpd1: %s%3d %s%3d %s%3d%s", COLOUR_RED, countIndex[CHAR_R], COLOUR_GREEN, countIndex[CHAR_G], COLOUR_BLUE, countIndex[CHAR_B], COLOUR_NONE);

		currentIndex++;
	}

	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c ", (*inputArray)[i]);
	}
}
void swapIndexValues(char **string, int index1, int index2)
{
	if (index1 < 0 || index2 < 0) return;

	char temp = (*string)[index1];
	(*string)[index1] = (*string)[index2];
	(*string)[index2] = temp;
}

