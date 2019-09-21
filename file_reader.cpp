#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

/* file_reader.cpp Takes in the name of a cluster info file and returns a
 * ClusterInfo struct. FIle is expected to be tab delimited.
 */

using namespace std;

// Forward declare functions
vector<string> string_splitter(string chunk, char delimiter);

ClusterInfo file_reader(string file_name)
{
    // Declare line delimiter
    char delimiter = '\t';

    // Create return struct
    ClusterInfo ret_clust;

    // Open file as an ifstream
    ifstream in_stream(file_name.c_str());

    // Check if open was successful
    if(!in_stream)
    {
        cout << "Could not open file\n";
        return ret_clust;
    }

    // Create cluster vector
    vector<string> clusters;
    // Create cluster placement vector
    vector<int> placement_flags;

    // String holder for each line
    string this_line;
    // Holder for both parts of a line
    vector<string> line_elements;

    // Read file line by line
    while(getline(in_stream, this_line))
    {
        if(this_line.size() > 0)
        {
            line_elements = string_splitter(this_line, delimiter);
            // Add cluster
            clusters.push_back(line_elements[0]);
            // Add its placement flag
            placement_flags.push_back(stoi(line_elements[1]));
        }
    }

    // Close the file
    in_stream.close();

    // Pack cluster info struct
    ret_clust.character_clusters = clusters;
    ret_clust.placement_flags = placement_flags;

    return ret_clust;
}