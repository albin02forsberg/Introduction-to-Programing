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

// Can't seem to solve this one yet... 

float areaCirc(int r) {
    float area = 0;

    for(int y = -r; y <= r; ++y){
        for(int x = -r; x <= r; ++x){
            if(x*x + y*y < r*r){
                area+= 1;
            }
        }
        area += std::sqrtf(r*r + y*y);
    }

    return area;
}

double approxPi(int r){
    return areaCirc(r) / (r*r);
}

void testPi(){
    for(int i = 1; i < 1000; i*=2){
        std::cout << approxPi(i) << std::endl;
    }
}

#endif // MATTE_H
