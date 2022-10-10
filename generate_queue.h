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
#include <cstring>

using namespace std;

struct SongObject
{
    string songName;
    int priority; 

    bool operator< (const SongObject &song1) const{
        return priority < song1.priority;
    }
};

int findWordFrequency(string songName,string word, map<string,vector<string>>& lyricMap);

void buildMatchingQueue(string query, map<string,vector<string>>& lyricMap,
         map<string,set<string>>& index, priority_queue<SongObject>& matchingSongsQueue);

void generate_SongDatabase(map<string, vector<string>>& lyricMap, 
           map<string, set<string>>& inverted_index);