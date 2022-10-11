/*
utils.h
----------------------------------------------------
Includes helper functions for analyzing and manipulating strings and vectors.
*/

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>
#include <sstream>

using namespace std; 

/* checks whether a string can be the text form of an integer (such as "24" or "150")
*/
bool isInteger(string str);

/* a templated function for truncating a C++ STL vector; it specifically will output 
a subvector whose elements are between indices left_index and right_index - 1, inclusive, of the input vector.
*/
template<typename type> vector<type> truncate_vector(vector<type> const &vec, int left_index, int right_index){
    int len = vec.size();
    if (min(left_index, right_index) < 0 || max(left_index,right_index) > len || left_index >= right_index){
        throw invalid_argument("Invalid left and right indices for vector truncation.");
    }
    vector<type> truncated_vector(right_index - left_index);
    copy(vec.begin() + left_index, vec.begin() + right_index, truncated_vector.begin());
    return truncated_vector;
}

/* functions for generating a printable string representation from integer and string vectors.
For instance, vecToString({1,2,3,4}) becomes "[1, 2, 3, 4, 5]". 
*/
string vecToString(vector<int> vec);
string vecToString(vector<string> vec);

/*
this function will split a string into tokens separated by a char delimiter,
and return a vector composed of the ordered tokens. 
*/
vector<string> split_string(string text, char delimiter);

/*
this function will take a lyrics string, split the lyrics into 
separate words, and then insert the words into a C++ set. 
*/
set<string> createWordSet(string lyrics);

/*
this function will create an identifier for a song by concatenating
the name of the song with the name(s) of the artists.
*/
string generateSongID(string songName, string authorName);

/*
this function will take a string, lower-case each of its characters,
and return the resulting string. 
*/
string tolower_string(string str);