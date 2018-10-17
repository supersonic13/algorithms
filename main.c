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
