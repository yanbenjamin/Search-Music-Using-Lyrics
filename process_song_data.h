#include <vector>
#include <string>
using namespace std;

int process_csv(string csvFile, vector< vector<string> >& file_contents);
int extract_songData(vector< vector<string> >& file_contents, 
    vector<string>& songNames, vector<string>& artists, 
    vector<string>& all_lyrics, vector<int>& rank, bool includes_header);