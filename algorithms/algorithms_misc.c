#include "common.h"

static int showMenu(void)
{
	int choice = 0;

	while (1)
	{
		printf (
				"\n"
				"\n%d. Merge"
				"\n%d. Exit"
				"\n",
				MISC_MERGE,
				MISC_EXIT
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

void algorithmsMisc(void)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0) break;

		switch (choice)
		{
			case MISC_MERGE:
				merge();
				break;
		}	
	}
}
