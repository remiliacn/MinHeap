#include <iostream>
#include "heap.h"
#include "util.h"
using namespace std;

Heap Initialize(int s){
    struct Heap h;
    h.capacity = s;
    h.size = 0;
    h.pointer = (ELEMENT*) malloc(sizeof(ELEMENT)*h.capacity);

    return h;
}

void BuildHeap(Heap h, ELEMENT arr[], int size){
    for (int idx = 0; idx < size; idx++){
        h.pointer[idx].key = arr[idx].key;
    }
}

void Insert(Heap *h, int flag, int key){
    if (flag == 2){
        printHeap(*h);
    }

    if (h->size == h->capacity){
        cout << "The capacity value is not big enough to hold more keys.";
    } else{
        int size = h->size;
        h->pointer[size].key = key;
        h->size += 1;

        while (size != 0 && h->pointer[parentIdx(size)].key > h->pointer[size].key){
            swap(&h->pointer[size].key, &h->pointer[parentIdx(size)].key);
            size = parentIdx(size);
        }
    }
}

int DeleteMin(Heap h, int flag){
    if (flag == 2){
        printHeap(h);
    }

    int size = h.size;
    if (size == 0){
        cout << "There are no elements in heap to delete.";
        return -1;
    }

    if (size == 1){
        h.size -= 1;
        return h.pointer[0].key;
    }

    int tempMin = h.pointer[0].key; h.pointer[0].key = h.pointer[size - 1].key;
    h.size -= 1;
    constructMinHeap(h, 0);
    return tempMin;
}

void DecreaseKey(Heap h, int flag, int index, int value){
    if (flag == 2){
        printHeap(h);
    }

    h.pointer[index].key = value;
    while (index != 0){
        if (h.pointer[parentIdx(index)].key > h.pointer[index].key){
            swap(&h.pointer[index].key, &h.pointer[parentIdx(index)].key);
            index = parentIdx(index);
        } else{
            break;
        }
    }
}

void printHeap(Heap h){
    printf("The capacity is %d.\n"
           "Size is %d\n", h.capacity, h.size);

    int size = h.size;

    for (int i = 0; i < size; i++){
        cout << h.pointer[i].key << endl;
    }
}

