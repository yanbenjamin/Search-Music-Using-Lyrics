/*
search.cpp
----------------------------------------------------
 Contains the main source code for providing fragmented lyrics 
 and getting ranked search results for plausible songs.
*/

#include "generate_queue.h"

vector<string> findMatchesAll(string query, map<string, vector<string>>& lyricMap, 
           map<string, set<string>>& inverted_index, int k){
    
    priority_queue<SongObject> matchingSongsQueue;
    buildMatchingQueue(query,lyricMap,inverted_index,matchingSongsQueue);

    int queue_size = matchingSongsQueue.size();
    
    vector<string> top_k_matches; 
    int current_song_idx = 1;
    
    while (current_song_idx <= k and current_song_idx <= queue_size){
        SongObject current_Song = matchingSongsQueue.top();
        matchingSongsQueue.pop();
        string name = current_Song.songName;
        top_k_matches.push_back(name);
        current_song_idx += 1;
    }

    return top_k_matches; 
}

int main(int argc, char *argv[]){

    if (argc < 3){
        return -1;
    }

    map<string, vector<string>> lyricMap;
    map<string, set<string>> inverted_index;
    generate_SongDatabase(lyricMap, inverted_index);

    string query = string(argv[1]);
    int k = atoi(argv[2]);

    vector<string> topKMatches = findMatchesAll(query,
                    lyricMap, inverted_index, k);
    
    int ranking = 1;
    for (string songMatch: topKMatches){
        cout << "(" << ranking << ") " << songMatch << endl;
        ranking += 1;
    }

}