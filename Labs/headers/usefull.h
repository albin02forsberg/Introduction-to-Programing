#ifndef USEFULL_H
#define USEFULL_H


//              ARRAY UTILITIES
//
//      Usefull functions for standard
//      arrays in c++
//
//

#include <stdlib.h>
#include <cassert>
#include <string>

// GENERAL UTILITIES

namespace usefull {

void printArray(const int arr[], int length){
    std::cout << "[ ";
    for(int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << "]" << std::endl;
}

int contains(const int arr[], int lenght, int x){
    for(int i = 0; i < lenght; i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}

// isSorted needs to have an array with min-length
// of two elements.

int isSorted(const int arr[], int lenght){
    assert(lenght > 1);
    for(int i = 0; i < lenght-1; i++){
        if(arr[i] <= arr[i+1]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

// SORTING ALGORITMS
// TODO fix bubbleSort

void bubbleSort(int arr[], int length){
    int counter = 1;
    int temp = 0;
    while(!isSorted(arr, length)){
        for(int i = 0;  i < length  - counter; i++){
            if(arr[i] >= arr[i+1]){
                temp = arr[i];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        counter++;
    }
}

void selectionSort(int arr[], int length){
    int indexOfMin = 0;
    int min;

    for(int i = 0; i < length; i++){
        min = arr[length-1];

        for(int j = i; j < length; j++){
            if(arr[j] <= min){
                min = arr[j];
                indexOfMin = j;
            }
        }

        arr[indexOfMin] = arr[i];
        arr[i] = min;
    }
}

// STRING FUCTIONS


std::string trim(const std::string str){
    int first = 0;
    for(int i = 0; i < str.size(); i++){
        if(!isspace(str[i])){
            first = i;
            break;
        }
    }

    int last = 0;

    for(int i = str.size(); i > 0; i--){
        if(!isspace(str[i])) {
            last = i;
            break;
        }
    }

    std::string trimmed = "";

    for(int i = first; i < last; i++){
        trimmed += str[i];
    }

    return trimmed;
}
}

#endif // USEFULL_H
