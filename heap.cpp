#include <iostream>
#include "heap.h"
#include "util.h"
using namespace std;

/**
 * This method is for initializing the heap.
 * @param s {int} The capacity to initialize the heap.
 * @return the heap that created from initializing.
 */
Heap Initialize(int s){
    struct Heap h;
    h.capacity = s;
    h.size = 0;
    h.pointer = (ELEMENT*) malloc(sizeof(ELEMENT)*h.capacity);

    return h;
}

/**
 * This method is for building heap from the file.
 * @param h {Heap} -> heap element for adding data from ELEMENT array.
 * @param arr {ELEMENT} -> ELEMENT array, acquired from file.
 * @param size {int} -> acquired from reading file.
 */
void BuildHeap(Heap *h, ELEMENT arr[], int size){
    //I created a helper function to build the heap.
    arr = buildHelper(arr, size);

    //Since ELEMENT array recorded data from index=1, thus when adding to the heap
    //it should be idx - 1
    //Copy ELEMENT keys -> Heap pointer.
    for (int idx = 1; idx < size + 1; idx++) {
        h->pointer[idx - 1].key = arr[idx].key;
        h->size += 1;
    }
}

/**
 * This method is for inserting {key} into the {Heap} object.
 * @param h {Heap} -> Get the content from the Heap object.
 * @param flag {int} -> To determine if print the heap before and after the method is executed or not.
 * @param key {int} -> Key to insert in the heap.
 */
void Insert(Heap *h, int flag, int key){
    //if flag is 2, print before insertion.
    if (flag == 2){
        printHeap(*h);
    }

    if (h->size == h->capacity){
        //cout << "The capacity value is not big enough to hold more keys.";
        //if it is already full, expand the capacity.
        h -> capacity *= 2;
        //reallocate memory for the heap.
        h -> pointer = (ELEMENT * )realloc(h -> pointer, h -> capacity * 2);

    }

    h->size += 1;
    int size = h->size - 1;
    h->pointer[size].key = key;

    //Insert the key and check if the min heap is in its supposed order.
    while (size != 0 && h->pointer[parentIdx(size)].key > h->pointer[size].key){
        swap(&h->pointer[size].key, &h->pointer[parentIdx(size)].key);
        size = parentIdx(size);
    }

    //if flag is 2, print the heap after the insertion.
    if (flag == 2){
        printHeap(*h);
    }
}

/**
 * This method will delete the min value from the heap and return it as an {int}.
 * @param h {Heap} -> Get the content from the Heap object.
 * @param flag {int} -> To determine if print the heap before and after the method is executed or not.
 * @return {int} -> Return the min value deleted.
 */
int DeleteMin(Heap *h, int flag){
    //Explained in Insert method.
    if (flag == 2){
        printHeap(*h);
    }

    int size = h->size;
    //check if all heap elements has been deleted.
    if (size == 0){
        cout << "There are no elements in heap to delete." << endl;
        return -1;
    }

    //return the last element from the heap.
    if (size == 1){
        h->size -= 1;
        return h->pointer[0].key;
    }

    //store the element for removing.
    int tempMin = h->pointer[0].key;

    h->pointer[0].key = h->pointer[size - 1].key;
    h->size -= 1;

    //reconstruct the minheap after deletion.
    constructMinHeap(*h, 0);

    if (flag == 2){
        printHeap(*h);
    }

    return tempMin;
}

/**
 * This method will decrease the key in the heap by index.
 * @param h {Heap} -> Get the content from the Heap object.
 * @param flag {int} -> To determine if print the heap before and after the method is executed or not.
 * @param index {int} -> index to delete from
 * @param value {int} -> value to modify.
 */
void DecreaseKey(Heap h, int flag, int index, int value){
    if (flag == 2){
        printHeap(h);
    }

    h.pointer[index].key = value;
    //check if the index is too big.
    if (index > h.size){
        cout << "There are only " << h.size << " in the heap. So this cannot be done." << endl;
        return;
    }

    while (index != 0){
        //decrease keys that is in the range of the index.
        if (h.pointer[parentIdx(index)].key > h.pointer[index].key){
            swap(&h.pointer[index].key, &h.pointer[parentIdx(index)].key);
            index = parentIdx(index);
        } else{
            break;
        }
    }
}

/**
 * Print the heap's content.
 * @param h {Heap} -> Get the content from the Heap object.
 */

void printHeap(Heap h){
    //print the information of the heap
    printf("The capacity is %d.\n"
           "Size is %d\n", h.capacity, h.size);

    int size = h.size;

    //print the heap content from beginning to the end.
    for (int i = 0; i < size; i++){
        cout << h.pointer[i].key << endl;
    }
}
