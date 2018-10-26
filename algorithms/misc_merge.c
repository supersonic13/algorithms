#include "common.h"


static void problemDescription(void)
{
	printf(
			"\nMerging array in place"
			);
}

static int problemOptions(void)
{
	printf(
			"\n"
			"\n0. Exit"
			/*"\n1. Use random array"*/
			/*"\n2. Enter sorted array values"*/
			"\n3. Default array values 1"
			"\n4. Default array values 1"
			"\n"
			);
	return readInputInteger();
}

void merge(void)
{
	clearScreen();
	problemDescription();

	int choice = problemOptions();	
	if (choice == 0) return;

	int numberOfArrayValues = 0;
	int low, mid, high;

	int *inputArray = NULL;
	/*if (choice == 1)*/
	/*{*/
		/*printf("\nEnter number of random values: ");*/
		/*numberOfArrayValues = readInputInteger();*/
		/*if (numberOfArrayValues <= 0) numberOfArrayValues = 10;*/
		/*srand(time(NULL));*/
		/*inputArray = (int *)(calloc(numberOfArrayValues, sizeof(char)));*/
		/*for (int i = 0; i < numberOfArrayValues; i++)*/
		/*{*/
			/*inputArray[i] = rand() % 100;*/
		/*}*/
	/*}*/
	/*else */
	/*if (choice == 2)*/
	/*{*/
		/*int numberOfArrayValues = readInputIntegerArray(inputArray);*/
		/*printf("\nNumber of values: %d", numberOfArrayValues);*/
		/*if (!inputArray) {printf("Invalid input"); return;}*/
		/*printf(*/
				/*"Enter MID index value (0 ... %d)",*/
				/*numberOfArrayValues-1*/
				/*);*/
		/*low = 0;*/
		/*high = numberOfArrayValues -1;*/
		/*mid = readInputInteger();*/
	/*}*/
	/*else */
	if (choice == 3)
	{
		numberOfArrayValues = 8;
		inputArray = (int *)(calloc(numberOfArrayValues, sizeof(int)));
		inputArray[0] = 2;
		inputArray[1] = 7;
		inputArray[2] = 15;
		inputArray[3] = 17;
		inputArray[4] = 10;
		inputArray[5] = 11;
		inputArray[6] = 12;
		inputArray[7] = 20;
		low = 0;
		mid = 3;
		high = 7;
	}
	else if (choice == 4)
	{
		numberOfArrayValues = 10;
		inputArray = (int *)(calloc(numberOfArrayValues, sizeof(int)));
		inputArray[0] = 1;
		inputArray[1] = 10;
		inputArray[2] = 20;
		inputArray[3] = 100;
		inputArray[4] = 120;
		inputArray[5] = 160;
		inputArray[6] = 6;
		inputArray[7] = 70;
		inputArray[8] = 88;
		inputArray[9] = 99;
		low = 0;
		mid = 5;
		high = 9;
	}

	if (inputArray)
	{
		merge_algo(inputArray, low, mid, high);
		free(inputArray);
	}
}

void merge_algo(int * inputArray, int low, int mid, int high)
{
	printf ("\n");
	for (int i = 0; i <= high; i++)
	{
		i >= low ? printf("%d ", inputArray[i]) : printf("  ");
	}
	printf ("\n");

	int i = low;
	int j = mid + 1;

	while (j <= high && i <= high)
	{
		while (inputArray[i] <= inputArray[j])	
		{
			i++;
		}

		while (inputArray[j] > inputArray[i])
		{
			j++;
		}

		printf ("\n");
		for (int k = 0 ; k <= high; k++)
		{
			const char *colour = COLOUR_NONE;
			if (k == i || k == j) colour = COLOUR_GREEN;
			k >= low ? printf("%s%d %s", colour, inputArray[k], COLOUR_NONE) : printf("  ");
		}
		
		int count = j;
		while (count > i)
		{
			swapIntArrayIndex(inputArray, count, count-1);
			printf("\n");
			for (int k = 0; k <= high; k++)
			{
				const char *swapSymbol = " ";
				const char *colour = COLOUR_NONE;
				if (k == count-1) {swapSymbol = "⇄"; }
				if (k == count-1) {colour = COLOUR_RED;}
				k >= low ? printf("%s%d%s%s", colour, inputArray[k], swapSymbol, COLOUR_NONE) : printf("  ");
			}
			count--;
		}
		j++;
		i++;

		printf ("\n");
		for (int k =low; k <= high; k++)
		{
			const char *colour = COLOUR_NONE;
			k >= low ? printf("%s%d %s", colour, inputArray[k], COLOUR_NONE) : printf("  ");
		}
		printf ("\n");
	}

	printf ("\n");
	for (int k = 0; k <= high; k++)
	{
		k >= low ?  printf("%d ", inputArray[k]) : printf("  ");
	}
}
