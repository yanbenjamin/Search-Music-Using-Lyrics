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
#include "process_song_data.h"

using namespace std;
using namespace std::chrono;

int process_csv(string csvFile, vector< vector<string> >& file_contents){
    string row;
    fstream file(csvFile, ios::in);
    if (file.is_open()){
        while (getline(file, row)){
            vector<string> row_contents; 
            stringstream stream(row);
            string cell;
            while (getline(stream, cell,',')){
                row_contents.push_back(cell);
            }
            file_contents.push_back(row_contents);
        }
    }
    else{
        cout << "Error with opening the file " << csvFile << endl;
        return -1;
    }
    return file_contents.size(); //number of lines read 
}

int extract_songData(vector< vector<string> >& file_contents, 
    vector<string>& songNames, vector<string>& artists, 
    vector<string>& all_lyrics, vector<int>& rank, bool includes_header){

    int numSongs = 0;
    int startIndex = (includes_header) ? 1 : 0;

    for (int i = startIndex; i < file_contents.size(); i++){
        vector<string> entry = file_contents[i];
        if (isInteger(entry[3])){
            //identifies the requisite information for each song entry in the .csv file
            string artist = entry[2];
            artist = entry[1];
            string songName = entry[4] + " (" + entry[5] + ")";
            string lyrics = entry[9];
            int songRank = stoi(entry[3]);

            //adds the song information to each of the vectors passed in by reference
            songNames.push_back(songName);
            artists.push_back(artist);
            all_lyrics.push_back(lyrics);
            rank.push_back(songRank);
            numSongs++;
        }
    }
    return numSongs;
}