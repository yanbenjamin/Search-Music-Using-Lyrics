/*
generate_queue.h
----------------------------------------------------
Creates an STL C++ priority queue that ranks songs according to a query 
based on (1) how many words in the query appear in the song and 
(2) how frequent those word in the song are.
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
#include <cstring>

using namespace std;

/* a custom C++ struct used to store information about a song's name and priority,
and used as elements in the search priority queues. 
*/
struct SongObject
{
    string songName;
    int priority; 

    bool operator< (const SongObject &song1) const{
        return priority < song1.priority;
    }
};


/*
This function accepts a song name and a word and identifies the number of times that
the word appears with the song lyrics, returning the frequency as an integer
 */
int findWordFrequency(string songName,string word, map<string,vector<string>>& lyricMap);

/*
this function uses maps from songs to lyrics and words to songs that contain them 
in order to rank song candidates based on how well they match the words in a search query. 
Ranking is based on (1) the number of words in the query that are in the song's lyrics 
and (2) the frequency of those mutual words in the lyrics.
*/
void buildMatchingQueue(string query, map<string,vector<string>>& lyricMap,
         map<string,set<string>>& index, priority_queue<SongObject>& matchingSongsQueue);

/*
function that populates the lyricMap and inverted_index map parameters 
with entries from the song data in billboard-lyrics.csv. lyricMap consists of 
(song, lyrics) pairs and inverted_index consists of (word, songs that contain word) pairs
*/
void generate_SongDatabase(map<string, vector<string>>& lyricMap, 
           map<string, set<string>>& inverted_index);