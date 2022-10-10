#include "utils.h"
#include <string>
#include <iostream>
using namespace std;

bool isInteger(string str){
    for (int i = 0; i < str.length(); i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}
