#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>
#include "usefull.h"


void fillArray(int arr[], int length, int value){
    for(int i = 0; i < length; i++){
        arr[i] = value;
    }
}

void fillArrayRandom(int arr[], int length, int min, int max){
    srand( (unsigned)time( NULL ) );
    for(int i = 0; i < length; i++){
        arr[i] = (std::rand()%max) + 1;
    }
}

int arrayBig(const int arr[], int length){
    int n = arr[0];
    for(int i = 0; i < length; i++){
        if(arr[i] >= n){
            n = arr[i];
        }
    }
    return n;
}

int indexArraySmall(const int arr[], int lenght){
    int small = arr[0];
    int index = 0;
    for(int i = 0; i < lenght; i++){
        if(arr[i] <= small){
            small = arr[i];
            index = i;
        }
    }
    return index;
}

int indexArrayBig(const int arr[], int length){
    int big = arrayBig(arr, length);

    for(int i = 0; i < length; i++){
        if(arr[i] == big){
            return i;
        }
    }

    return 0;
}



void arrayTest(){
    int length = 6;
    int arr[length];
    
    std::cout << "Fill array with value" << std::endl;
    fillArray(arr, length, 5);

    std::cout << "Print array" << std::endl;
    usefull::printArray(arr, length);

    std::cout << "Fill array with random value" << std::endl;
    fillArrayRandom(arr, length, 1 , 10);
    usefull::printArray(arr, length);

    std::cout << "The bigest number is: " << std::endl
              << arrayBig(arr, length) << std::endl;

    std::cout << "Sorting array: " << std::endl;

    usefull::selectionSort(arr, length);
    usefull::printArray(arr, length);


    std::cout << "Arrayen är sorterad: " << usefull::isSorted(arr, length) << std::endl;

    std::cout << "Arrayen innehåller 6? " << usefull::contains(arr, length, 6) << std::endl;
}

#endif // ARRAHS_H
