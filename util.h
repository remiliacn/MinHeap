#ifndef UTIL_HEADER
#define UTIL_HEADER

#include "heap.h"

//Header for util.cpp
void readFromTxt(Heap *h);
void swap (int* x, int* y);
int parentIdx(int num);
int leftNode(int num);
int rightNode(int num);
void constructMinHeap(Heap h, int num);

//Methods below are for making my life easier
ELEMENT* buildHelper(ELEMENT arr[], int size);
void constructMinHeap(ELEMENT arr[], int size, int num);

#endif