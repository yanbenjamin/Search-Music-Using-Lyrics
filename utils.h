#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>
#include <sstream>

using namespace std; 

bool isInteger(string str);

template<typename type> vector<type> truncate_vector(vector<type> const &vec, int left_index, int right_index){
    int len = vec.size();
    if (min(left_index, right_index) < 0 || max(left_index,right_index) > len || left_index >= right_index){
        throw invalid_argument("Invalid left and right indices for vector truncation.");
    }
    vector<type> truncated_vector(right_index - left_index);
    copy(vec.begin() + left_index, vec.begin() + right_index, truncated_vector.begin());
    return truncated_vector;
}

string vecToString(vector<int> vec);
string vecToString(vector<string> vec);