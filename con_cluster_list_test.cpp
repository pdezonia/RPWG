#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>

/* con_cluster_list_test.cpp Loads a very short list of consonant clusters
 * to help with code testing. */

using namespace std;

ClusterInfo con_cluster_list_test()
{
	vector<string> con_list = {"s", "d", "f", "sh", "k", "ch"};
	vector<vector<int>> placement_flags =  {{1, 1, 1},
						{1, 1, 1},
						{0, 0, 1},
						{1, 0, 0},
						{1, 1, 0},
						{0, 0, 1}};
	// ClusterInfo consonant_info { con_list, placement_flags };
	ClusterInfo consonant_info;
	consonant_info.character_clusters = con_list;
	consonant_info.placement_flags = placement_flags;
	return consonant_info;
}
