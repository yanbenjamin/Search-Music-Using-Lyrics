/*
process_song_data.h
----------------------------------------------------
Includes tools for reading the lyrics csv file 
and encoding the song information in data strctures.
*/

#include <vector>
#include <string>
using namespace std;

/*
reads the CSV file and dumps its contents into the file_contents, which is a vector 
of rows (and each row is a vector of elements such as song name, artist name, year, etc.)
*/
int process_csv(string csvFile, vector< vector<string> >& file_contents);

/*
from the file_contents in the CSV file, this function will extract out vectors 
containing the song names, artists, lyrics, etc. 
*/
int extract_songData(vector< vector<string> >& file_contents, 
    vector<string>& songNames, vector<string>& artists, 
    vector<string>& all_lyrics, vector<int>& rank, bool includes_header);