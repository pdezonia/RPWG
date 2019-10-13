#include "cluster_info.h"
#include "rpwg_fwd_dec.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

/* file_reader.cpp Takes in the name of a cluster info file and returns a
 * ClusterInfo struct. FIle is expected to be tab delimited.
 */

using namespace std;


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
    // Create cluster frequency vector
    vector<int> frequency_scores;

    // String holder for each line
    string this_line;
    // Holder for both parts of a line
    vector<string> line_elements;
    vector<string> meta_data;

    // Read file line by line
    while(getline(in_stream, this_line))
    {
        if(this_line.size() > 0)
        {
            // First call returns [cluster, [pos_code, freq]]
            line_elements = string_splitter(this_line, delimiter);
            meta_data = string_splitter(line_elements[1], 
                                                   delimiter);

            // cout << line_elements[0] << "\n";
            // cout << meta_data[0] << " " << meta_data[1]
            //      << "\n";

            // Add cluster to end of vector
            clusters.push_back(line_elements[0]);
            // Add its placement flag
            placement_flags.push_back(stoi(meta_data[0]));
            // Add its frequency stat
            frequency_scores.push_back(stoi(meta_data[1]));
        }
    }

    // Close the file
    in_stream.close();

    // Pack cluster info struct
    ret_clust.character_clusters = clusters;
    ret_clust.placement_flags = placement_flags;
    ret_clust.frequency_scores = frequency_scores;

    return ret_clust;
}