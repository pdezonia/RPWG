#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* string_splitter.cpp Takes in a string and a delimiter character and splits
 * the string once. Returns both strings in a vector.
 */

using namespace std;

vector<string> string_splitter(string chunk, char delimiter)
{
    string token_1;
    string token_2;

    // Used to signify end of line, allows for multiple calls of this function
    // to break up a line multiple times.
    char end_of_line = '\n';

    stringstream ss;
    ss << chunk;
    // Get first part of string
    getline(ss, token_1, delimiter);
    // Get second part of string
    getline(ss, token_2, end_of_line);

    vector<string> ret_vec = {token_1, token_2};
    return ret_vec;
}