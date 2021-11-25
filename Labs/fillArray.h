#ifndef FILLARRAY_H
#define FILLARRAY_H

#include <iostream>
#include "headers/usefull.h"

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0 && n != 2){
            return false;
        }
    }

    return true;
}

void fillPrimes(int arr[], int n){
    int primes = 1 ;
    int current = 3;
    while(primes <= n) {
        if(isPrime(current)){
            arr[primes] = current;
            primes += 1;
        }
        current++;
    }
}


void testFillArray(){
//    int length = 10;
//    int arr[length];
//    std::cout << "Fill arrays" << std::endl;

//    std::cout << "Fill with primes" << std::endl;
//    fillPrimes(arr, length);
//    arr[0] = 2;
//    usefull::printArray(arr, length);

    int varv = 0;

    for(int i=0; i < 10; ++i){
        if(i==8){
            break;
        }
        varv += 1;
    }

    std::cout << varv << std::endl;

}


#endif // FILLARRAY_H
