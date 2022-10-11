/*
generate_queue.cpp
----------------------------------------------------
Source code implementation of the functions described in generate_queue.h
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

#include "utils.h"
#include "build_data_maps.h"
#include "process_song_data.h"
#include "generate_queue.h"

using namespace std;

/*
This function accepts a song name and a word and identifies the number of times that
the word appears with the song lyrics, returning the frequency as an integer
 */
int findWordFrequency(string songName,string word, map<string,vector<string>>& lyricMap){
    vector<string> lyrics = lyricMap[songName];
    int count = 0;
    for (string s: lyrics){
        if (s == word){
            count++;
        }
    }
    return count;
}

void buildMatchingQueue(string query, map<string,vector<string>>& lyricMap,
         map<string,set<string>>& index, priority_queue<SongObject>& matchingSongsQueue){

   double MAX_SONG_LENGTH = 10e5;
   vector<string> searchWords = split_string(query,' ');
   
   //a potential match is any song containing at least one word in the query
   set<string> potentialMatches;
   for (string word: searchWords){
       set<string> current_matches = index[tolower_string(word)];
       potentialMatches.insert(current_matches.begin(), current_matches.end());
   }
   // goes through all potential matches, assigns them a priority based on how well 
   // the lyrics match with the search query, and inserts them into a priority queue. 
   for (string song: potentialMatches){  
       int aggregate_frequency = 0;
       int numMatchingWords = 0;
       for (string word: searchWords){  
           int word_frequency = findWordFrequency(song,tolower_string(word),lyricMap); 
           if (word_frequency > 0){
               numMatchingWords += 1;
           }
          aggregate_frequency += findWordFrequency(song,tolower_string(word),lyricMap);
       }
       
       SongObject songobj; // song object stores both songname and priority
       songobj.priority = MAX_SONG_LENGTH * numMatchingWords + aggregate_frequency;
       songobj.songName = song; 
       matchingSongsQueue.push(songobj);
       
   }
}


void generate_SongDatabase(map<string, vector<string>>& lyricMap, 
           map<string, set<string>>& inverted_index){
    
    // extracts artist, song name, and lyrical information from the .csv file
    string filename = "billboard-lyrics.csv";
    vector< vector<string> > fileContents;
    vector<string> names; 
    vector<string> artists;
    vector<string> all_lyrics; 
    vector<int> rank; 
    bool includes_header = true;
    int numSongs;
    if (process_csv(filename, fileContents) != -1){
        numSongs = extract_songData(fileContents, names, artists, all_lyrics, rank, includes_header);
    }
    else{
         throw invalid_argument("Unable to open the csv file");
    }

    //generates an identifier for each song by concatenating the name with its artists
    vector<string> songNames;
    for (int i = 0; i < names.size(); i++){
        songNames.push_back(generateSongID(names[i],artists[i]));
    }

    buildLyricMap(songNames,all_lyrics,lyricMap);

    map<string, int> songRankings;
    for (int i = 0; i < songNames.size(); i++){
        songRankings[songNames[i]] = rank[i];
    }

    vector<set<string>> wordSets;
    for (int i = 0; i < all_lyrics.size(); i++){
        wordSets.push_back(createWordSet(all_lyrics[i]));
    }
    buildInvertedIndex(songNames,wordSets,inverted_index);
}
