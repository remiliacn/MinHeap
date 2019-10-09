#include <iostream>
#include <string>
#include <fstream>
#include "heap.h"

using namespace std;

/**
 * Read data from a file
 * @param h {Heap} -> Get the content from the Heap object.
 */
void readFromTxt(Heap *h){
    //Attempt to open the file HEAPinput.txt
    ifstream infile("HEAPinput.txt");
    //Check if the file exists.
    if (infile.good()) {
        int i = 1;
        int size;

        infile >> size;
        //check if the size is too much for the heap to handle.
        if (size > h->capacity){
            cout << "Sorry this is not possible, since capacity is lower than the size" << endl;
            return;
        }

        ELEMENT arr[size + 1];
        arr[0].key = size;
        //add them to ELEMENT array.
        while (i < size + 1){
            infile >> arr[i].key;
            i++;
        }
        //using BuildHeap function to make the heap.
        BuildHeap(h, arr, size);
        infile.close();

    } else{
        cout << "File \"HEAPinput.txt\" does not exist in the current directory." << endl;
    }
}

int main(){
    string str;
    char command;
    struct Heap h = Heap();
    bool init = false;
    int size, flag, key, length;
    while (1){
        //Read input from user.
        getline(cin, str);
        //Get command's length.
        length = str.length();
        //Fetch the command.
        command = str[0];

        switch (command){
            case '\t':
            case '\n':
                continue;

            //Exit the program.
            case 'S':
            case 's':
                cout << "Program will shut down now." << endl;
                exit(1);

            case 'C':
            case 'c':
                //check syntax.
                if (length < 3){
                    cout << "invalid input, no size was given." << endl;
                } else{
                    try{
                        //Get the capacity
                        string rest = str.substr(2, length);
                        size = stoi(rest);
                        h = Initialize(size);
                        init = true;

                        //check if the input is valid.
                    } catch (invalid_argument &){
                        cout << "Invalid size, it should be a number." << endl;
                        //check if the input is too big.
                    } catch (out_of_range &) {
                        cout << "Your input is too big for my program to handle :(." << endl;
                    }
                }
                break;

            case 'R':
            case 'r':
                //Check the syntax.
                if (str.length() != 1){
                    cout << "Invalid Input!!!" << endl;
                    break;
                } else{
                    readFromTxt(&h);
                }
                break;

            case 'W':
            case 'w':
                //Check if heap is initialized or not.
                if (!init){
                    cout << "The heap is not initialized yet, please initialize first!" << endl;
                } else{
                    printHeap(h);
                }

                break;

            case 'I':
            case 'i':
                if (!init){
                    cout << "The heap is not initialized yet, please initialize first!" << endl;
                } else{
                    if (length < 5){
                        cout << "Invalid input or arguments are not enough." << endl;
                    } else{
                        flag = str[2] - '0';
                        //check if flag argument is legal.
                        if ((flag == 2 || flag == 1)){
                            try{
                                key = stoi(str.substr(4, length));
                                Insert(&h, flag, key);

                                //check if the key input is legal.
                            } catch (invalid_argument &) {
                                cout << "Entered key seems to not be a number. Try again." << endl;
                            } catch (out_of_range &){
                                cout << "Key is too big!!!!" << endl;
                            }

                        } else{
                            cout << "variable \"flag\" is illegal.";
                        }
                    }
                }

                break;

            case 'D':
            case 'd':
                if (!init){
                    cout << "You need to initialize the heap before using this function." << endl;
                } else{
                    flag = str[2] - '0';
                    if (flag <= 0 || flag > 2){
                        cout << "Illegal flag input." << endl;
                    } else{
                        int tempKey = DeleteMin(&h, flag);
                        //check if deleteMin() encountered an error.
                        if (tempKey != -1){
                            cout << "deleted key was: " << tempKey << endl;
                        }
                    }
                }
                break;

            case 'K':
            case 'k':
                if (!init){
                    cout << "You need to initialize the heap before using this function." << endl;
                } else{
                    if (length < 7){
                        cout << "Invalid syntax, please check again." << endl;
                    } else{
                        flag = str[2] - '0';
                        if (flag == 1 || flag == 2){
                            if (flag <= 0 || flag > 2){
                                cout << "Illegal flag input.";
                            } else{
                                str = str.substr(4, length);
                                int delimiterPos = str.find(' ');
                                try{
                                    //break down the argument index and value by delimiter whitespace
                                    int index = stoi(str.substr(0, delimiterPos));
                                    int v = stoi(str.substr(delimiterPos + 1, str.length()));
                                    //Pass the args into DecreaseKey()
                                    DecreaseKey(h, flag, index, v);
                                }

                                catch (invalid_argument &){
                                    cout << "Either the input of index, or the input of value is not a number." << endl;
                                }
                            }
                        } else{
                            cout << "argument \"flag\" is not a number" << endl;
                        }
                    }
                }
                break;

            default:
                cout << "Invalid command!!" << endl;
        }

        cout << "COMMAND: " << str << endl;
    }
}

/**
 * Swap two elements' position.
 * @param x {int*} -> first swap element
 * @param y {int*} -> second swap element
 */
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Return the parent node's position from giving index.
 * @param num {int} -> Index to get the parent node position.
 * @return {int} -> Parent node's position.
 */
int parentIdx(int num){
    return (num) / 2;
}

/**
 * Return the left node's position from giving index.
 * @param num {int} -> Index to get the left node position.
 * @return {int} -> Left node's position.
 */
int leftNode(int num){
    return 2 * num ;
}

/**
 * Return the right node's position from giving index.
 * @param num {int} -> Index to get the right node position.
 * @return {int} -> Right node's position.
 */
int rightNode(int num){
    return 2 * num + 1;
}

/**
 * Construct the min heap's content from the position given.
 * @param h {Heap} -> The heap object that is currently using.
 * @param num {int} -> The position for checking if the minHeap is legal.
 */
void constructMinHeap(Heap h, int num){
    //Same algorithm is featured below.
    if (num < 0)
        return;

    int size = h.size;
    int left = leftNode(num);
    int right = rightNode(num);
    int min = num;

    if (left < size && h.pointer[left].key < h.pointer[num].key){
        min = left;
    }

    if (right < size && h.pointer[right].key < h.pointer[min].key){
        min = right;
    }

    if (min != num){
        swap(&h.pointer[num].key, &h.pointer[min].key);
        constructMinHeap(h, min);
    }
}

/**
 * Construct the min heap called from BuildHeap.
 * @param arr {ELEMENT[]} -> Integer array gathered from HEAPinput.txt
 * @param size {int} -> The size of ELEMENT arr[]
 * @param num {int} -> The current position.
 */
void constructMinHeap(ELEMENT arr[], int size, int num){
    //if num is negative number, then terminate the current recursive session.
    if (num < 0)
        return;

    //Set left and right node.
    int left = leftNode(num);
    int right = rightNode(num);
    int min = num;

    //Check if the left node has a smaller value
    if (left < size && arr[left].key < arr[min].key){
        min = left;
    }

    //Check if the right node has a smaller value
    if (right < size && arr[right].key < arr[min].key){
        min = right;
    }

    if(min != num){
        //swap the current node with the smaller node.
        swap(&arr[num].key, &arr[min].key);
        //Recursive the process.
        constructMinHeap(arr, size, min);
    }
}

/**
 * A helping method for constructing the min heap.
 * @param arr {ELEMENT[]} -> Integer array gathered from HEAPinput.txt
 * @param size {int} -> Size of the ELEMENT arr[]
 * @return {ELEMENT*} -> Return the Minheapified array.
 */
ELEMENT* buildHelper (ELEMENT arr[], int size){
    //Initialize the very last node position
    int i = size + 1;
    while (i >= 1){
        //construct a min heap with recursion.
        constructMinHeap(arr, size + 1, i);
        i--;
    }

    return arr;
}