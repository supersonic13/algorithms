#include "common.h"

#define clear() printf("\033[H\033[J")


void clearScreen(void)
{
	clear();
}

int readInputInteger(void)
{
	char inputString[100];
	scanf("%s", inputString);
	int choice = atoi(inputString);
	return choice;
}

char * readInputString(void)
{
	char inputString[100];
	scanf("%s", inputString);
	char *returnStr = strdup(inputString);
	return returnStr;
}

int readInputIntegerArray(int *inputArray)
{
	char inputString[100];
	scanf("%s", inputString);
	/*char *returnStr = strdup(inputString);*/
	int staticIntArray[100];
	int numberCount = 0;
	int * intArray = NULL;
	char *token = NULL;
	char *tokenend = NULL;

	token = strtok_r(inputString, " ", &tokenend);

	while(token != NULL)
	{
		staticIntArray[numberCount] = atoi(token);
		numberCount++;
		token = strtok_r(NULL, " ", &tokenend);
	}
	
	if (numberCount > 0)
	{
		intArray = (int *)calloc(numberCount, sizeof(int));
		for (int i = 0; i < numberCount; i++) intArray[i] = staticIntArray[i];
	}

	return numberCount;
}

void swapIntArrayIndex(int *inputArray, int index1, int index2)
{
	int temp = inputArray[index1];
	inputArray[index1] = inputArray[index2];
	inputArray[index2] = temp;
}

static int showMenu(void)
{
	int choice = 0;

	while (1)
	{
		printf (
				"\n"
				"\n%d. Algorithms"
				"\n%d. Problems"
				"\n%d. Exit"
				"\n",
				ALGORITHMS,
				PROBLEMS,
				EXIT
				);

		choice = readInputInteger();
		if (choice < 0)
		{
			printf("\nInvalid input");
			continue;
		}
		break;
	}

	return choice;
}

int main(int argc, char **argv)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0) break;

		switch (choice)
		{
			case ALGORITHMS:
				algorithmsMain();
				break;
			case PROBLEMS:
				codingProblemsMain();
				break;
		}
	}

	return 0;
}
