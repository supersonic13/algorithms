#ifndef _ALGO_COMMON_H
#define _ALGO_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define COLOUR_RED "\033[0;31m"
#define COLOUR_GREEN "\033[0;32m"
#define COLOUR_YELLOW "\033[0;33m"
#define COLOUR_NONE "\033[0m"

void printIntArray(int *inputArray, int size);
void printIntArrayHighlight(const char *prefix, int *inputArray, int startIndex, int endIndex, int index1, int index2, int index3);
void genRandomValues(int *inputArray, int size);
int getRandomValue(int max);

void sorting(void);

#endif // _ALGO_COMMON_H

