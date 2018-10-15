#include "common.h"

enum {SORT_EXIT, SORT_QUICKSORT};

#define DEFAULT_ARRAY_SIZE	10

#define VISUALISE_ENUM	99
int gVisualise = 0;
#define VISUALISE	if(gVisualise){char ch; scanf("%c", &ch);}

void quickSort(int *inputArray, int size);
void quickSortHelper(int *inputArray, int first, int last);
int quickSortPartition(int *inputArray, int first, int last);
void swap(int *inputArray, int index1, int index2);

void getBigO(int algo)
{
	printf(
			"\n\tWorst case\tAverage case\tBest case"
			);
	switch(algo)
	{
		case SORT_QUICKSORT:
			printf(
					"\nQuicksort\tO(n^2)\tO(n log{n})\tNA"
					);
			break;
	}
}

static int showMenu(void)
{
	int choice = -1;
	while(1)
	{
		printf(
				"\nSort menu"
				"\n%d. QuickSort"
				"\n%d. BigO and Exit"
				"\n%d. Toggle visualise"
				"\n",
				SORT_QUICKSORT,
				SORT_EXIT,
				VISUALISE_ENUM
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

void sorting(void)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0)
		{
			break;
		}

		if (choice == VISUALISE_ENUM)
		{
			gVisualise = !gVisualise; 
		}

		int arraySize = DEFAULT_ARRAY_SIZE;
		int *inputArray = (int *)calloc(arraySize, sizeof(int));
		genRandomValues(inputArray, arraySize);
		
		getBigO(choice);
		
		printIntArrayHighlight("Initial array\t\t", inputArray, 0, arraySize-1, -1, -1, -1);


		switch(choice)
		{
			case SORT_QUICKSORT:
				quickSort(inputArray, arraySize);
				break;
		}

		/*printIntArray(inputArray, arraySize);*/
		printIntArrayHighlight("Final array\t\t", inputArray, 0, arraySize-1, -1, -1, -1);

		free(inputArray);
	}
}

void quickSort(int *inputArray, int size)
{
	printf(
			"\n------"
			"\nQuicksort"
			"\n------"
			""
		  );
	printf (
			"\nBasic steps:"
			COLOUR_YELLOW
			"\n1. Divide by choosing any element in the subarray array[p..r]. Call this element the pivot." 
			"\n   Rearrange the elements in array[p..r] so that all elements in array[p..r] that are less than or equal to the pivot are to its left and all elements that are greater than the pivot are to its right."
			"\n   We call this procedure partitioning. At this point, it doesn't matter what order the elements to the left of the pivot are in relation to each other, and the same holds for the elements to the right of the pivot. We just care that each element is somewhere on the correct side of the pivot."
			"\n2. Conquer by recursively sorting the subarrays array[p..q-1] (all elements to the left of the pivot, which must be less than or equal to the pivot) and array[q+1..r] (all elements to the right of the pivot, which must be greater than the pivot)."
			"\n3. Combine by doing nothing. Once the conquer step recursively sorts, we are done. Why? All elements to the left of the pivot, in array[p..q-1], are less than or equal to the pivot and are sorted, and all elements to the right of the pivot, in array[q+1..r], are greater than the pivot and are sorted. The elements in array[p..r] can't help but be sorted!"
			COLOUR_NONE
			);

	quickSortHelper(inputArray, 0, size-1);
		
}

void quickSortHelper(int *inputArray, int low, int high)
{
	if (low < high)
	{
		printIntArrayHighlight("Sub-array\t\t", inputArray, low, high, low, high, -1);
		int pivot = quickSortPartition(inputArray, low, high);
		
		printIntArrayHighlight("Partition\t\t", inputArray, low, high, -1, -1, pivot);
		quickSortHelper(inputArray, low, pivot - 1);
		quickSortHelper(inputArray, pivot + 1, high);
	}
}

int quickSortPartition(int *inputArray, int low, int high)
{
	int pivot = inputArray[high];
	int i = low - 1;

	for (int j = low; j <= high -1 ; j++)
	{
		VISUALISE;
		if (inputArray[j] <= pivot)
		{
			VISUALISE;
			i++;
			if (i != j)
			swap(inputArray, i, j);
		}
	}

	swap (inputArray, i + 1, high);
	return i + 1;
}

void swap(int *inputArray, int index1, int index2)
{
	VISUALISE;	
	char sMessage[64] = "";
	snprintf(sMessage, sizeof(sMessage)-1, "Swap index %d & %d\t", index1, index2);
	printIntArrayHighlight(sMessage, inputArray, index1, index2, index1, index2, -1);
	/*printf("\t\t\tSwap %d & %d", index1, index2);*/
	int temp = inputArray[index1];
	inputArray[index1] = inputArray[index2];
	inputArray[index2] = temp;
}
