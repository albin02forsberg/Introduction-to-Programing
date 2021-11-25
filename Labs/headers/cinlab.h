#ifndef CINLAB_H
#define CINLAB_H

#include <iostream>
#include <stdlib.h>
#include "string"

double getDoubleCin(std::string promt){
    std::cout << promt << std::endl;
    double n = 0;
    std::cin >> n;
    return n;
}

char getCharCin(std::string promt){
    std::cout << promt << std::endl;
    char n = 0;

    std::cin >> n;

    return n;
}

double result(double n1, double n2, char op){
    switch(op){
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
        default:
            std::cout << "Invalid expression" << std::endl;
            return 0;
    }

}

void printResult(double n, double n2, char op){
    double res = result(n, n2, op);

    std::cout << res << std::endl;
}

void testCin(){
    double n1;
    double n2;
    char op;
    /*
    while(true){

        std::cin << n1 << op << n2;

        std::cout << n1 << op << n2;

    }
    */
}


#endif // CINLAB_H

