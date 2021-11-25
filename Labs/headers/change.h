#ifndef CHANGE_H
#define CHANGE_H

#include <iostream>
#include <stdlib.h>

void change(int n){
    const int valueCount = 8;
    int values[valueCount] = {500, 200, 100, 20, 10, 5, 2, 1};

    for(int i = 0; i < valueCount; i++){
        if(n/values[i] != 0){
            std::cout << n / values[i] << " x " 
                  << values[i] << " kr" << std::endl;
        }

        n -= (n / values[i]) * values[i];
    }
}

#endif // CHANGE_H

