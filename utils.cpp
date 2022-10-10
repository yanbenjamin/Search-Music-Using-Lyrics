#include "utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

bool isInteger(string str){
    for (int i = 0; i < str.length(); i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

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
