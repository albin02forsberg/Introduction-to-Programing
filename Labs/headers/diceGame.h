#ifndef DICEGAME_H
#define DICEGAME_H

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <time.h>
#include "usefull.h"

/*
RULES:

1. To play one round cost 10 sek
2. Tre dices are thrown (number between 1-6)
3. If all dices are sixes, player wins 100 sek
4. If all dices are equal, player wins 50 sek
5. If two dices are equal, player wins 20 sek
6. If no dices are equal, player loses 10 sek
*/

bool continueGame(std::string prompt){
    std::cout << prompt << std::endl;
    char input;

    while(true){
        std::cin >> input;
        switch (input){
            case 'y':
                return true;
            case 'n':
                return false;
            default: 
                std::cout << "Invalid input\n" << prompt << std::endl;
                continue;
        }
    }
}

std::vector<int> throwDice(int n = 3){
    std::vector<int> dices;
    srand(unsigned(std::time(nullptr)));

    for(int i = 0; i < n; i++){
        dices.push_back(1 + (rand() % 6));
    }

    return dices;
}

std::vector<int> setVector(int n = 6){
    std::vector<int> vect;
    for(int i = 0; i < n; i++){
        vect.push_back(0);
    }

    return vect;
}

std::vector<int> getHistogram(std::vector<int> dices){
    std::vector<int> histogram = setVector();

    for(int i = 0; i < dices.size(); i++){
        histogram[dices[i]-1] += 1;
    }

    return histogram;
}

int isWin(std::vector<int> dices){
    std::vector<int> histogram = getHistogram(dices);

    if(histogram[5] == 3){
        return 100;
    }

    int counter = 0; 

    for(int i = 0; i < histogram.size(); i++){
        if(histogram[i] >= counter){
            counter = histogram[i];
        }
    }

    if(counter == 3){
        return 50;
    } else if(counter == 2){
        return 20;
    }

    return 0;
}

void gameLoop(){
    int money = 100;
    while(money >= 10){
        std::cout << "You have: " << money << " sek" << std::endl;
        if(continueGame("Do you want to play? (y/n)")){
            money -= 10;
            std::vector<int> dices = throwDice();
            usefull::printArray(dices);
            if(isWin(dices) > 0){
                std::cout << "Congratulations! You won " + std::to_string(isWin(dices)) + " sek\n";
                money += isWin(dices);
            } else {
                std::cout << "You lost...\n";
            }
        } else {
            std::cout << "You left with " << money << " sek\n";
            break;
        }
    }

    if(money <= 0){
        std::cout << "You have no money left...\n";
    }

}

void gameAnalisis(){
    std::vector<int> rounds;
    int money = 100;
    int rounds = 0;
    for(int i = 0; i < 1000000; i++){
        money = 100;
        rounds = 0;
        while(money >= 10){
            rounds += 1;
            std::vector<int> dices = throwDice();
        }
    }
}

void testDiceGame(){
    gameLoop();
}

#endif // DICEGAME_H