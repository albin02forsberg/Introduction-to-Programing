#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

// THIS PROGRAM DOES NOT WORK YET!!

std::vector<std::string> readWordList(){
    std::string filename = "./words.txt";

    std::ifstream file(filename);
    std::vector<std::string> wordList;

    while(!file.fail()){
        std::string word;
        file >> word;

        if(!file.fail()){
            wordList.push_back(word);
        }
    }

    return wordList;

}

void printWordList(const std::vector<std::string> wordList){
    std::cout << "Matches: " << std::endl;
    for(int i = 0; i < wordList.size(); i++){
        std::cout << i+1 << "\t" << wordList[i] << std::endl;
    }
}

// bool contains(std::string words, std::string chr){
//     for(int i = 0; i < words.size(); i++){
//         if(words[i] == chr){
//             return true;
//         }
//     }
//     return false;
// }

bool isJoker(std::string word, std::string joker){
    bool match = false;
    for(int j = 0; j < word.size(); j++){
        if(joker[j] == '?'){
            match = true;
            continue;
        }
        if(word[j] == joker[j]){
            match = true;
        }else {
            match = false;
            break;
        }
    }

    return match && word.size() == joker.size();
}

std::vector<std::string> getConcat(std::string wild){

    std::vector<std::string> returnVector;

    std::string front;
    for(int i = 0; i < wild.size(); i++){
        if(wild[i] == '*'){
            break;
        } else {
            front.push_back(wild[i]);
        }
    }

    returnVector.push_back(front);

    std::string back;
    for(int i = wild.size(); i >= 0; i--){
        if(wild[i] == '*'){
            break;
        } else {
            back.push_back(wild[i]);
        }
    }

    returnVector.push_back(back);

    return returnVector;
}


bool isWild(std::string word, std::string wild){
    // std::vector<std::string> strings = getConcat(wild);

    // return(matchFront(word, strings[0]) && matchBack(word, strings[1]));

    // TODO Write RegEx

    std::vector<std::string> fb = getConcat(wild);

    std::regex reg ("(" + fb[0] + ")" + "([A-Za-z?]){0,}" + "(" + fb[1] + ")$/gm");

    if(std::regex_match(word, reg)){
        std::cout << "Match: " << word << std::endl;
        return true;
    } else {
        // std::cout << "No match: " << word << std::endl;
        return false;
    }
}

// Get matches for the given string str
// and searches throw the words vector for
// matches.
std::vector<std::string> getMatches(std::string str, const std::vector<std::string>& words){
    std::vector<std::string> matches;
    bool joker = false;
    bool wild = false;
    for(int i = 0; i < words.size(); i++){
        // Check for words with joker '?'
        joker = isJoker(words[i], str);
        // Check for words with wildcard '*'
        wild = isWild(words[i], str);

        if(joker || wild ){
            matches.push_back(words[i]);
        }
    }

    return matches;
}

std::vector<std::string> parseInput(const std::string str, const std::vector<std::string>& words){
    // Check for matches
    std::vector<std::string> matches = getMatches(str, words);

    return getMatches(str, words);
}

// Loops until the user types "exit", needs
// a vectors with words and calls the function parseInput
// with the users keyword and the words vector.

void input(const std::vector<std::string>& words){
    std::string keyword;

    while(true){
        std::cout << "Enter word: ";
        std::cin >> keyword;
        if(keyword == "exit"){
            break;
        }
        std::vector<std::string> matches = parseInput(keyword, words);

        printWordList(matches);
    }
}


void testReadFile(){
    std::cout << "Read File Test\n";

    std::vector<std::string> words = readWordList();
    // printWordList(words);

    input(words);
}

#endif // READFILE_H
