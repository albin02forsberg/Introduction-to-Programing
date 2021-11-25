#ifndef IOSTEST_H
#define IOSTEST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>


void test(){
    std::string filename = "./test.txt";
    
    std::ofstream outStream;

    outStream.open("./test.txt");

    for(int i = 0; i < 10; i++){
        outStream << "Row: " << i << std::endl;
    }

    outStream.close();
}

void svgTest(){
    std::string filename = "./svg.svg";

    std::ofstream outStream;

    outStream.open(filename);

    outStream << "<svg viewBox=\"-110 -110 220 220\"" << std::endl << "xmlns=\"http://www.w3.org/2000/svg\"" << std::endl
              << "version=\"1.1\">" << std::endl << "<path d=\"M 0 0" << std::endl
              << "L -100 0" << std::endl << "L -100 50" << std::endl << "L 0 100" << std::endl << "L 100 -100" << std::endl
              << "L -100 -100" << std::endl << "\"" << std::endl << "fill=\"white\" stroke=\"red\" stroke-width=\"3\" />"
              << std::endl << "</svg>";

    outStream.close();
}

double getXCord(double deg, double r){
    return r*std::cos(deg*M_PI/180);
}

double getYCord(double deg, double r){
    return r*std::sin(deg*M_PI/180);
}

void hexagonSvg(){
    std::string filename ="./hexagon.svg";
    std::ofstream  outStream;
    outStream.open(filename);

    outStream << "<svg viewBox=\"-110 -110 220 220\" " << std::endl
              << "xmlns=\"http://www.w3.org/2000/svg\"" << std::endl
              << "version =\"1.1\">" << std::endl
              << "<path d=\"M 100 0 " << std::endl;
    double r = 100;
    double space = 0.95;
    while(r >= 5){
        for(int i = 0; i < 6; i++){
            double g = i*360/6;
            outStream << "L " << getXCord(g, r) << " " << getYCord(g, r) << std::endl;
        }
        r *= space;
    }


    outStream << "\"" << std::endl << "fill=\"white\" stroke=\"green\" stroke-width=\"1\" />" << std::endl << "</svg>";
}

void ioTest(){
    std::cout << "Hello IO" << std::endl;
    hexagonSvg();
}


#endif // IOSTEST_H
