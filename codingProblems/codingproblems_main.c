#include "common.h"

static int showMenu(void)
{
	int choice = 0;

	while (1)
	{
		printf (
				"\n"
				"\n%d. DCP #35"
				"\n%d. Exit"
				"\n",
				PROBLEMS_DCP35,
				PROBLEMS_EXIT
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

void codingProblemsMain(void)
{
	while(1)
	{
		int choice = showMenu();
		if (choice == 0) break;

		switch (choice)
		{
			case PROBLEMS_DCP35:
				dcp35();
				break;
		}	
	}
}
