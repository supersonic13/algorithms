#include "common.h"

static int showMenu(void)
{
	int choice = 0;

	while (1)
	{
		printf (
				"\n"
				"\n%d. Sorting"
				"\n%d. Exit"
				"\n",
				ALGO_SORTING,
				ALGO_EXIT
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

void algorithmsMain(void)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0) break;

		switch (choice)
		{
			case ALGO_SORTING:
				algorithmsSorting();
				break;
		}	
	}
}
