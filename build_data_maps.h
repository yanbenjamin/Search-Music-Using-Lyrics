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

using namespace std;

/* builds an index ADT Map that maps each word to the songs that contain them */
void buildInvertedIndex(vector<string>& songNames, vector< set<string> >& wordSets,map< string,set<string> >& index);

/* builds an ADT map that corresponds each song title with the vector of word lyrics,
mainly for the purpose of frequency counting */
void buildLyricMap(vector<string>& songNames, vector<string>& all_lyrics, map<string,vector<string>>& lyricMap);

