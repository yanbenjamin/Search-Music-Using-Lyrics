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

#include "process_song_data.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){

    string filename = "billboard-lyrics.csv";
    vector< vector<string> > fileContents;

    vector<string> songNames; 
    vector<string> artists;
    vector<string> all_lyrics; 
    vector<int> rank; 
    bool includes_header = true;

    int numSongs;

    auto initial = high_resolution_clock::now();
    
    if (process_csv(filename, fileContents) != -1){
        numSongs = extract_songData(fileContents, songNames, artists, all_lyrics, rank, includes_header);
    }
    else{
        cout << "Error in opening the csv file" << endl;
        return -1;
    }
    auto final = high_resolution_clock::now();
    auto timespan = duration_cast< duration<double> >(final - initial);

    int num_songs_to_sample = 10;

    cout << "Number of Songs in " << filename << ": " << numSongs << endl;

    cout << "First " << num_songs_to_sample << " Song Names: " << vecToString(truncate_vector(songNames,0,10)) << endl;
    cout << "First " << num_songs_to_sample << " Artists: " << vecToString(truncate_vector(artists,0,10)) << endl;
    cout << "First " << num_songs_to_sample << " Ranks: " << vecToString(truncate_vector(rank,0,10)) << endl;

}