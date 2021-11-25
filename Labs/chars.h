#ifndef CHARS_H
#define CHARS_H

#include <iostream>
#include <string>

bool isSame(const char str1[], const char str2[]){
    int i = 0;
    while(str1[i] != 0 || str2[i] != 0){
        if(str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return true;
}

void toUpper(char str[]){
    for(int i = 0; str[i] != 0; i++ ){
        str[i] = toupper(str[i]);
    }
    std::cout << str << std::endl;
}

void toHeader(char str[]){
    for(int i = 0; str[i] != 0; i++){
        if(i == 0 || std::isspace(str[i-1])){
            str[i] = toupper(str[i]);
        }
    }

    std::cout << str << std::endl;
}

bool isVowel(char chr){
    char str[] = "aeiouyAEIOUY";

    for(int i = 0; str[i] != 0; i++){
        if(chr == str[i]){
            return true;
        }
    }

    return false;
}

bool isConsonant(char chr){
    char str[] = "bcdfghjklmnpqrstvzxVCDFGHIJKLMNPQRSTVZX";

    for(int i = 0; str[i] != 0; i++){
        if(chr == str[i]){
            return true;
        }
    }

    return false;
}

std::string trim(const std::string str){
    int first = 0;
    for(int i = 0; i < str.size(); i++){
        if(!isspace(str[i])){
            first = i;
            break;
        }
    }

    int last = 0;

    for(int i = str.size(); i > 0; i--){
        if(!isspace(str[i])) {
            last = i;
            break;
        }
    }

    std::string trimmed = "";

    for(int i = first; i < last; i++){
        trimmed += str[i];
    }

    return trimmed;
}

std::string iSprik(std::string str){
    for(int i = 0; i < str.size(); i++){
        if(isVowel(str[i])){
            if(isupper(str[i])){
                str[i] = 'I';
            } else {
                str[i] = 'i';
            }
        }
    }

    return str;
}

std::string rovarSprak(std::string str){
    std::string sentence = "";

    for(int i = 0; i < str.size(); i++){
        if(isConsonant(str[i])){
            sentence.push_back(str[i]);
            sentence.push_back('o');
            sentence.push_back(str[i]);
        } else {
            sentence.push_back(str[i]);
        }
    }

    return sentence;
}

bool isRovarSprak(std::string str){
    bool isRov = false;
    for(int i = 0; i < str.size(); i++){
        if(isspace(str[i])){
            continue;
        }
        if(isConsonant(str[i]) && str[i+1] == 'o' && str[i+2] == str[i]){
            isRov = true;
            i+=2;
        } else {
            isRov = false;
        }
    }
    return isRov;
}

std::string translateRovar(std::string str){
    assert(isRovarSprak(str));

    std::string translated = "";

    for(int i = 0; i < str.size(); i++){
        if(isConsonant(str[i]) && str[i+1] == 'o' && str[i+2] == str[i]){
            translated.push_back(str[i]);
            i+=2;
            continue;
        }
        translated.push_back(str[i]);
    }

    return translated;
}


void testChars(){
    assert( translateRovar("poprorogogroramommomerorinongog aror kokulol")
                     == "programmering ar kul" );

    std::cout << translateRovar("poprorogogroramommomerorinongog aror kokulol") << std::endl;
}

#endif // CHARS_H
