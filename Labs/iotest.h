#ifndef IOSTEST_H
#define IOSTEST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

void test(){
    std::string filename = "../test.txt";
    
    std::ofstream outStream;

    outStream.open("./test.txt");

    for(int i = 0; i < 10; i++){
        outStream << "Row: " << i << std::endl;
    }

    outStream.close();
}

void ioTest(){
    std::cout << "Hello IO" << std::endl;
}


#endif // IOSTEST_H
