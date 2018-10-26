#ifndef _ALGO_COMMON_H
#define _ALGO_COMMON_H

#include "../common.h"

enum {ALGO_EXIT, ALGO_SORTING, ALGO_MISC};

enum {SORT_EXIT, SORT_QUICKSORT, SORT_MERGESORT};

enum {MISC_EXIT, MISC_MERGE};

void algorithmsMain(void);

// Sort algorithms
void algorithmsSorting(void);
void quickSort(void);
void mergeSort(void);


// Misc algorithms
void algorithmsMisc(void);
void merge(void);
void merge_algo(int * inputArray, int low, int mid, int high);

#endif
