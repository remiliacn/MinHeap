#ifndef UTIL_HEADER
#define UTIL_HEADER

#include "heap.h"

void readFromTxt(Heap *h);
void swap (int* x, int* y);
int parentIdx(int num);
int leftNode(int num);
int rightNode(int num);
void constructMinHeap(Heap h, int num);

#endif