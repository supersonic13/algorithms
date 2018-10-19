#include "common.h"

static int showMenu(void)
{
	int choice = 0;

	while (1)
	{
		printf (
				"\n"
				"\n%d. Quicksort"
				"\n%d. Exit"
				"\n",
				SORT_QUICKSORT,
				SORT_EXIT
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

void algorithmsSorting(void)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0) break;

		switch (choice)
		{
			case SORT_QUICKSORT:
				quickSort();
				break;
		}	
	}
}
