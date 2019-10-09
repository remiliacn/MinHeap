#ifndef HEAP_HEADER
#define HEAP_HEADER

struct Heap{
    int capacity;
    int size;
    struct ELEMENT *pointer;
};

struct ELEMENT{
    int key;
};


Heap Initialize (int n);
void BuildHeap(Heap *h, ELEMENT arr[], int n);
void Insert(Heap *h, int flag, int key);
int DeleteMin(Heap *h, int flag);
void DecreaseKey(Heap h, int flag, int index, int value);

void printHeap(Heap h);


#endif