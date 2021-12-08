#ifndef PTRREF_H
#define PTRREF_H

#include <iostream>
#include <cassert>
#include <time.h>
#include <cstdlib>
#include <iomanip>

void swapVal(int *Pa, int *Pb){
    int temp = *Pa;
    *Pa = *Pb;
    *Pb = temp;
}

void swapVal(double *Pa, double *Pb){
    double temp = *Pa;
    *Pa = *Pb;
    *Pb = temp;
}

void automattestaBytVarden(){
        std::cout << "Testar swapVal" << std::endl;
        int a = 1;
        int b = 2;
        swapVal(&a, &b);
        assert( a==2 && b==1 );
        double x = 1.5;
        double y = 2.5;
        swapVal(&x, &y);
        assert( x==2.5 && y==1.5 );
        std::cout << "Testet av swapVal lyckades!" << std::endl;
}

bool isSameStr(const char *str1, const char *str2){
    int i = 0;
    while(str1[i] != 0 || str2[i] != 0){
        if(str1[i] != str2[i]){
            return false;
        }
        i++;
    }

    return true;
}

void toUpperP(char *str){
    for(int i = 0; str[i] != 0; i++){
        str[i] = std::toupper(str[i]);
    }
}

void convertToHeaderP(char *str){
    for(int i = 0; str[i] != 0; i++){
        if(i == 0 || std::isspace(str[i-1])){
            str[i] = std::toupper(str[i]);
        } else {
            str[i] = std::tolower(str[i]);
        }
    }
}

void printStringsP(const char** strings, int counter){
    for(int i = 0; i < counter; i++){
        std::cout << strings[i] << std::endl;
    }
}

void automattestaStrangfunktionerP(){
    std::cout << "automattestar strangfunktionerna-P" << std::endl;
    assert( isSameStr("abcd", "abcd") );
    assert( !isSameStr("abcd", "abcX") );
    assert( !isSameStr("abcd", "Xbcd") );
    assert( !isSameStr("abcd e", "abcd") );
    assert( !isSameStr("abcd", "abcd e") );
    char strA[] = "abc ABC 123 .,- xyz";
    char strB[] = "ABC ABC 123 .,- XYZ";
    toUpperP( strA );
    assert( isSameStr(strA, strB) );
    char str1[] = "this is a test";
    char str2[] = "THIS IS A TEST";
    char rubrik[] = "This Is A Test";
    char tom[] = "";
    convertToHeaderP( str1 );
    convertToHeaderP( str2 );
    convertToHeaderP( tom );
    assert( isSameStr(str1, rubrik) );
    assert( isSameStr(str2, rubrik) );
    assert( isSameStr(tom, "") );
    std::cout << "testen av strangfunktionerna-P lyckades!" << std::endl;
}

void testPrintStr(){
    const int count = 7;
    const char *dayName[count] = {"Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday", "Sunday"};
    
    printStringsP(dayName, count);
}

void fillArrayP(int *pStart, int *pEnd, int value){
    for(int *pData = pStart; pData!=pEnd; pData++){
        *pData = value;
    }
}

void printArrayP(int *pStart, int *pEnd){
    for(int *pData = pStart; pData!=pEnd; pData++){
        std::cout << *pData << " ";
    }

    std::cout << std::endl;
}

bool isSortedP(int *pStart, int *pEnd){
    for(int *pData = pStart; pData!=pEnd-1; pData++){
        if(*pData <= *(pData+1)){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void fillWithRandom(int *pStart, int *pEnd, int min, int max){
    std::srand((unsigned)time(nullptr));

    for(int *pData = pStart; pData!=pEnd; pData++){
        *pData = (rand() % (max + 1 - min)) + min;
    }
}

int maxP(int *pStart, int *pEnd){
    int max = 0;
    for(int *pData = pStart; pData!=pEnd; pData++){
        if(*pData >= max){
            max=*pData;
        }
    }

    return max;
}

int minP(int *pStart, int *pEnd){
    int min = 0;
    for(int *pData = pStart; pData!=pEnd; pData++){
        if(*pData <= min){
            min=*pData;
        }
    }

    return min;
}

bool containsP(int *pStart, int *pEnd, int value){
    for(int *pData = pStart; pData!=pEnd; pData++){
        if((*pData) == value){
            return true;
        }
    }

    return false;
}

void testArrayFunctionsP(){
    std::cout << "testar arrayfunktionerna -P " << std::endl;
    const int storlek = 10;
    int arr[storlek];
    fillArrayP(&arr[0], &arr[storlek], 5);
    printArrayP(&arr[0], &arr[storlek]);
    arr[0] -= 1;
    arr[storlek-1] += 1;
    assert( isSortedP(&arr[0], &arr[storlek]) );
    arr[0] = 6;
    printArrayP(&arr[0], &arr[storlek]);
    assert( !isSortedP(&arr[0], &arr[storlek]) );
    fillWithRandom(&arr[0], &arr[storlek], -2, 2);
    printArrayP(&arr[0], &arr[storlek]);
    arr[1] = -3; // Detta blir det minsta värdet
    arr[storlek-1] = 3;  // Detta blir det största värdet
    printArrayP(&arr[0], &arr[storlek]);
    int m = minP(&arr[0], &arr[storlek]);
    int s = maxP(&arr[0], &arr[storlek]);
    assert( m == -3 && s == 3 );
    assert( containsP(&arr[0], &arr[storlek], 3));
    std::cout << "testar av arrayfunktionerna -P lyckades" << std::endl;
}

char* cStringCopy(const char *str){
    int len = 0;
    for(int i = 0; i < 100; i++){
        if(*(str-1) == '0'){
            break;  
        } else {
            len++;
        }
    }
    char* strCopy[len];

    std::cout << "Lenght: " << len << std::endl;

    for(int i = 0; i < len; i++){
        *strCopy[i] = str[i];
    }

    delete [] str;

    return *strCopy;
}

char* getString(const char* prompt){
    std::cout << prompt;
    char str[100];
    std::cin >> std::setw(100) >> str;

    return cStringCopy(str);
}

void testCString(){
    const char* firstName = getString("Your first name: ");
    const char* lastName = getString("Your last name: ");

    std::cout << "Hello " << firstName << " " << lastName << "!\n";

    delete [] firstName;
    delete [] lastName;
}


void testPtrRef(){
    std::cout << "Testing pointers and references\n";
    testCString();
}

#endif // PTRREF_H