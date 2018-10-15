
#include "common.h"

enum {ALGO_EXIT, ALGO_SORTING};

static int showMenu(void);
int main(int argc, char **argv)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0)
		{
			break;
		}

		switch(choice)
		{
			case ALGO_SORTING:
				sorting();
				break;
		}
	}
	return 0;
}

int showMenu(void)
{
	int choice = 0;
	while (1)
	{
		printf(
				"----\n"
				"Menu\n"
				"----\n"
				"%d. Sorting\n"
				"%d. Exit"
				"\n",
				ALGO_SORTING,
				ALGO_EXIT
				);

		char inputString[100];
		scanf("%s", inputString);
		choice = atoi(inputString);
		if (choice < 0)
		{
			printf("\nInvalid input");
		}
		else
		{
			break;
		}

	}

	return choice;
}

void printIntArray(int *inputArray, int size)
{
	printIntArrayHighlight("\t\t", inputArray, 0, size-1, -1, -1, -1);
}

void printIntArrayHighlight(const char *prefix, int *inputArray, int startIndex, int endIndex, int index1, int index2, int index3)
{
	printf("\n%s", prefix);
	for(int i = 0; i <= endIndex; i++)
	{
		if (i < startIndex)
		{
			printf("  \t");
			continue;

		}
		char *colourHighlight = COLOUR_NONE;
		if (i == index1 || i == index2)	colourHighlight = COLOUR_RED;
		else if (i == index3) colourHighlight = COLOUR_YELLOW;
		printf("%s|%d|%s\t", colourHighlight, inputArray[i], COLOUR_NONE);
	}
}

void genRandomValues(int *inputArray, int size)
{
	srand((unsigned) time(NULL));
	for(int i = 0; i < size; i++)
	{
		inputArray[i] = rand() % 100;
	}
}

int getRandomValue(int max)
{
	srand((unsigned) time(NULL));
	return rand() % max;
}
