#ifndef MATTE_H
#define MATTE_H

#include <iostream>
#include <cmath>

double macLaurin(int e){
    int i = 20;
    double sum = 1;

    while (i != 0){
        double t = 1;
        double n = 1;
        for(int j = 1; j <= i; j++){
            t = t * e;
            n = n * j;
        }
        sum += (t / n);
        i--;
    }

    return sum;
}

// Calculates approximately the area of a circe

float areaCirc(int radius) {
    float area = 0;

    for(int y = -radius; y <= radius; ++y){
        for(int x = -radius; x <= radius; ++x){
            if(x*x + y*y < radius*radius ){
                area += 1;
            }
        }
    }

    return area;
}

// Breaks out Pi from the equation A = Pi*r^2 and calculates approximately Pi

double approxPi(int radius){
    return areaCirc(radius) / (radius * radius);
}

// Test function to approximate the value of Pi

void testPi(){
    for(int radius = 1; radius < 100000; radius = radius * 2){
        std::cout << approxPi(radius) << std::endl;
    }
}

#endif // MATTE_H
