#include "utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <set>
#include <sstream>
using namespace std;

/*
determines if a string describes an integer or not, such as '24' for instance.
*/
bool isInteger(string str){
    for (int i = 0; i < str.length(); i++){
        if (!isdigit(str[i])){ // ensures that all characters are digits
            return false;
        }
    }
    return true;
}

/* 
this function on int vectors converts the vector into a string
representation [int1, int2, int3, ...]
*/
string vecToString(vector<int> vec){
    if (vec.size() == 0){
        return "[]";
    }  
    string vecString = "[";
    for (int i = 0; i < vec.size(); i++){
        if (i < vec.size() - 1){
            vecString += (to_string(vec[i]) + ", ");
        }
        else{ 
            vecString += (to_string(vec[i]) + "]");
        }
    }
    return vecString;
}

/* 
this function on string vectors converts the vector into a string
representation [string1, string2, string3, ...]
*/
string vecToString(vector<string> vec){
    if (vec.size() == 0){
        return "[]";
    }  
    string vecString = "[";
    for (int i = 0; i < vec.size(); i++){
        if (i < vec.size() - 1){
            vecString += (vec[i] + ", ");
        }
        else{ 
            vecString += (vec[i] + "]");
        }
    }
    return vecString;
}

/* splits a string into a vector of tokens using a specific delimiter */
vector<string> split_string(string text, char delimiter){
    stringstream stream(text);
    string token; 
    vector<string> tokens; 
    while (getline(stream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

/* generates a set of words from the lyrics string */
set<string> createWordSet(string lyrics){
    set<string> wordSet = {};
    vector<string> wordVector = split_string(lyrics,' ');
    for (string word: wordVector){
        wordSet.insert(word);
    }
    return wordSet;
}

/* combines the song name with the artist to form the full song description */
string generateSongID(string songName, string authorName){
    return songName + " | " + authorName;
}


