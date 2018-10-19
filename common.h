#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>

#include "algorithms/common.h"
#include "codingProblems/common.h"

enum {EXIT, ALGORITHMS, PROBLEMS};

#define COLOUR_RED "\033[0;31m"
#define COLOUR_GREEN "\033[0;32m"
#define COLOUR_YELLOW "\033[0;33m"
#define COLOUR_BLUE "\033[0;34m"
#define COLOUR_NONE "\033[0m"

// Helper APIs
int readInputInteger(void);
char * readInputString(void);
//int readInputChar(void);
//int readInputString(void);
int readInputIntegerArray(int *inputArray);
//int readInputCharArray(void);
//int readInputString(void);

void clearScreen(void);


#endif
