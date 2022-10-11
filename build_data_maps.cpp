/*
build_data_maps.cpp
----------------------------------------------------
Source code implementation of the functions described in build_data_maps.h
*/

#include <iostream>
#include <fstream>
#include "errno.h"
#include <string>
#include <map>
#include <set> 
#include <queue> 
#include <stdlib.h>
#include <stdio.h> 
#include <vector>
#include <sstream>

#include "utils.h"
#include "build_data_maps.h"

using namespace std;

/* builds an index ADT Map that maps each word to the songs that contain them */
void buildInvertedIndex(vector<string>& songNames, vector< set<string> >& wordSets,map< string,set<string> >& index){
    int i = 0;
    for (string name: songNames){
        set<string> words = wordSets[i];
        for (string word: words){
            if (index.find(word) != index.end()){
                index[word].insert(name);
            }
            else{
                index[word] = {name};
            }
        }
        i++;
    }
}

/* builds an ADT map that corresponds each song title with the vector of word lyrics,
mainly for the purpose of frequency counting */
void buildLyricMap(vector<string>& songNames, vector<string>& all_lyrics, map<string,vector<string>>& lyricMap){
    for (int i = 0; i < songNames.size(); i++){
        lyricMap[songNames[i]] = split_string(all_lyrics[i],' ');
    }
}