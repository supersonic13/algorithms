#include "common.h"


void quickSort_algo(int * inputArray, int size);

static void problemDescription(void)
{
	printf(
			"\nQuicksort"
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

void quickSort(void)
{
	clearScreen();
	problemDescription();

	int choice = problemOptions();	
	if (choice == 0) return;

	int numberOfArrayValues = 0;

	int *inputArray = NULL;
	if (choice == 1)
	{
		printf("\nEnter number of random values: ");
		numberOfArrayValues = readInputInteger();
		if (numberOfArrayValues <= 0) numberOfArrayValues = 10;
		srand(time(NULL));
		inputArray = (int *)(calloc(numberOfArrayValues, sizeof(char)));
		for (int i = 0; i < numberOfArrayValues; i++)
		{
			inputArray[i] = rand() % 100;
		}
	}
	else if (choice == 2)
	{
		numberOfArrayValues = readInputIntegerArray(inputArray);
		if (!inputArray) {printf("Invalid input"); return;}
	}
	else if (choice == 3)
	{
		numberOfArrayValues = 8;
		inputArray = (int *)(calloc(numberOfArrayValues, sizeof(int)));
		inputArray[0] = 10;
		inputArray[1] = 5;
		inputArray[2] = 50;
		inputArray[3] = 100;
		inputArray[4] = 2;
		inputArray[5] = 0;
		inputArray[6] = 7;
	}

	if (inputArray)
	{
		quickSort_algo(inputArray, numberOfArrayValues);
		free(inputArray);
	}
}

void quickSort_algo(int * inputArray, int size)
{
	printf ("\n");
	for (int i=0; i < size; i++)
	{
		printf("%d ", inputArray[i]);
	}
}
