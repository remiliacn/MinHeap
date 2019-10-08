#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include "heap.h"

using namespace std;

void readFromTxt(Heap *h){

    ifstream infile("HEAPinput.txt");
    if (infile.good()) {
        int i = 1;
        int size;

        infile >> size;
        int numArr[size];
        //ELEMENT arr[size];
        while (i <= size){
            infile >> numArr[i];
            //infile >> arr[i].key;
            Insert(h, 1, numArr[i]);
            i++;
        }

        //BuildHeap(h, arr, size);
        infile.close();

    } else{
        cout << "File \"HEAPinput.txt\" does not exist in the current directory.";
    }
}

int main(){
    string str;
    char command;
    struct Heap h;
    bool init = false;
    struct ELEMENT element;
    int size, flag, key, length;
    while (1){
        getline(cin, str);
        length = str.length();
        command = str[0];
        cout << "COMMAND: " << str << endl;

        switch (command){
            case '\t':
            case '\n':
                continue;

            case 'S':
            case 's':
                exit(1);

            case 'C':
            case 'c':
                if (length < 3){
                    cout << "invalid input, no size was given." << endl;
                } else{
                    try{
                        string rest = str.substr(2);
                        size = stoi(rest);
                        h = Initialize(size);
                        init = true;

                    } catch (invalid_argument &){
                        cout << "Invalid size, it should be a number." << endl;
                    }
                }

                break;

            case 'R':
            case 'r':
                if (str.length() != 1){
                    cout << "Invalid Input!!!" << endl;
                    break;
                } else{
                    readFromTxt(&h);
                }
                break;

            case 'W':
            case 'w':
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
                        if (isdigit(flag)){
                            try{
                                key = stoi(str.substr(4, length));
                                Insert(&h, flag, key);
                            }

                            catch (invalid_argument &) {
                                cout << "Entered key seems to not be a number. Try again." << endl;
                            }
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
                        int tempKey = DeleteMin(h, flag);
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
                        if (isdigit(flag)){
                            if (flag <= 0 || flag > 2){
                                cout << "Illegal flag input.";
                            } else{
                                str = str.substr(4, length);
                                int delimiterPos = str.find(' ');
                                try{
                                    int index = stoi(str.substr(0, delimiterPos));
                                    int v = stoi(str.substr(delimiterPos + 1, str.length()));
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
    }
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int parentIdx(int num){
    return (num - 1) / 2;
}

int leftNode(int num){
    return 2 * num + 1;
}

int rightNode(int num){
    return 2 * num + 2;
}

void constructMinHeap(Heap h, int num){
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
/*void ELEMENT::readFromFile() {
    ifstream infile("HEAPinput.txt");
    string line;
    if (infile.good()){
        while (getline(infile, line)){
            istringstream iss(line);

        }
    }
}*/
