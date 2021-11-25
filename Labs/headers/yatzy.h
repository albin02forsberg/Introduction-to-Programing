#ifndef YATZY_H
#define YATZY_H

#include <iostream>
#include "usefull.h"

namespace yatzy{

    // Generates five dices with random value

    void createHand(int arr[], int lenght = 5){
        srand( (unsigned)time( NULL ) );

        for(int i = 0; i < lenght; i++){
            arr[i] = (rand() % 6) + 1;
        }
    }

    // Creates a histogram with a counter on all the
    // dices on the players hand

    void histogram(int dices[], int arr[]){
        for(int i = 4; i >= 0; i--){
            for(int j = 1; j <= 6; j++){
                if(dices[i] == j){
                    arr[j-1] += 1;
                }
            }
        }
    }

    int checkBiggest(){
       // TODO Check pair, double pair, three of a king
       // TODO Check straith
       return 0;
    }

    void startYatzy(){
        std::cout << "Yatzy" << std::endl;
        int arr[5];
        int histo[] = {0,0,0,0,0,0};

        createHand(arr);
        usefull::printArray(arr,5);

        histogram(arr, histo);

        usefull::printArray(histo, 6);
    }
}

#endif // YATZY_H
