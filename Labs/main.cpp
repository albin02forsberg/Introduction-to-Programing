#include <iostream>
#include "headers/matte.h"
#include "headers/arrays.h"
#include "headers/change.h"
#include "headers/yatzy.h"
#include "headers/usefull.h"
#include "headers/fillArray.h"
#include "headers/chars.h"
#include "headers/cinlab.h"
#include "headers/iotest.h"
#include "headers/readfile.h"
// #include "headers/diceGame.h"
#include "headers/ptrref.h"
#include <fstream>
#include <sstream>

unsigned int konstig(std::string str1, std::string str2){
    for(unsigned int i = 0; i < str1.size() && i < str2.size(); i += 1){
        if(str2[i] == 'X'){
            continue;
        }
        if(tolower(str1[i]) != tolower(str2[i])){
            return i;
        }

    }
    return 99;

}

void testKonstig(){
    unsigned int x0 = konstig("abc", "abq");
    unsigned int x1 = konstig("ABC", "aXc");
    unsigned int x2 = konstig("abcdef", "aaaaa");
    unsigned int x3 = konstig("abc", "ABc");
    unsigned int x4 = konstig("abcde", "fghij");

    std::cout << x0 << std::endl
              << x1 << std::endl
              << x2 << std::endl
              << x3 << std::endl
              << x4 << std::endl;
}

void testFail(){
    std::string example = "12+13=25";

    std::istringstream stream(example);

    int tal1 = 42;
    int tal2 = 42;
    std::string str = "hej";
    char tecken = 'x';

    stream >> tecken >> tal1 >> str >> tal2;
    std::cout << tecken << std::endl << tal1 << std::endl << str << std::endl << tal2 << std::endl;

}

int f(std::string str){
    unsigned int i = 0;
    while(i < str.size() && str[i] == ' '){
        ++i;
    }

    return i;
}

void provaF(){
    std::string s1 = "   Hej!";
    std::string s2 = "       ";
    std::string s3 = "";

    std::cout << f(s1) << std::endl;
    std::cout << f(s2) << std::endl;
    std::cout << f(s3) << std::endl;
}

int main(){
    // testPtrRef();
    // std::string s1 = "   Hej!";
    // std::string s2 = "       ";
    // std::string s3 = "";

    // std::cout << f(s1) << std::endl
    //           << f(s2) << std::endl
    //           << f(s2) << std::endl;

    // testKonstig();

    // testFail();

    provaF();
}
