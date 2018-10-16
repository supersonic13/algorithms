#include "common.h"

void dcp35_algo(char **inputArray);
void swapIndexAndValues(char **string, int *index1, int *index2);

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
	problemOptions();

	int choice = problemOptions();	
	if (choice == 0) return;

	char *inputArray = NULL;
	
	if (choice == 3)
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

	int lastKnownIndex[CHAR_M] = {-1, -1, -1};

	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c ", (*inputArray)[i]);
	}

	int currentIndex = 0;
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
		printf("\tInitial:%s%3d %s%3d %s%3d%s", COLOUR_RED, lastKnownIndex[CHAR_R], COLOUR_GREEN, lastKnownIndex[CHAR_G], COLOUR_BLUE, lastKnownIndex[CHAR_B], COLOUR_NONE);
		
		switch((*inputArray)[currentIndex])
		{
			case 'R':
				if (lastKnownIndex[CHAR_R] < 0) lastKnownIndex[CHAR_R] = currentIndex;
				break;
			case 'G':
				if (lastKnownIndex[CHAR_G] < 0) lastKnownIndex[CHAR_G] = currentIndex;
				break;
			case 'B':
				if (lastKnownIndex[CHAR_B] < 0) lastKnownIndex[CHAR_B] = currentIndex;
				break;
		}

		printf("\tUpd1: %s%3d %s%3d %s%3d%s", COLOUR_RED, lastKnownIndex[CHAR_R], COLOUR_GREEN, lastKnownIndex[CHAR_G], COLOUR_BLUE, lastKnownIndex[CHAR_B], COLOUR_NONE);

		currentIndex++;
	}

	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c ", (*inputArray)[i]);
	}
}
void swapIndexAndValues(char **string, int *index1, int *index2)
{
	printf("\nSwap values at index %d (%c) & index %d (%c)", *index1, (*string)[*index1], *index2, (*string)[*index2]);
	char temp = (*string)[*index1];
	(*string)[*index1] = (*string)[*index2];
	(*string)[*index2] = temp;

	int tempInt = *index1;
	*index1 = *index2;
	*index2 = tempInt;
}

