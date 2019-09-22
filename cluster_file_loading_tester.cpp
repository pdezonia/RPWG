#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* cluster_file_loading_tester.cpp For testing string splitting, loading 
 * strings from a text file, and putting them into vectors.
 */

using namespace std;

// Forward declare functions
vector<string> string_splitter(string chunk, char delimiter);
ClusterInfo file_reader(string file_name);

int main()
{
    string comma_test = "Hello\tworld";

    vector<string> two_strings;
    two_strings = string_splitter(comma_test, '\t');

    cout << two_strings[0] << " and " << two_strings[1] << '\n';

    string test_file_name = "cluster_file_loading_test.txt";

    ClusterInfo file_cluster_info;
    file_cluster_info = file_reader(test_file_name);

    cout << file_cluster_info.character_clusters[5] 
         << file_cluster_info.placement_flags[5] << '\n';
}