#include "cluster_info.h"

#include <string>
#include <vector>

/* vow_cluster_list_test.cpp Loads a very short list of vowel clusters
 * to help with code testing. */

ClusterInfo vow_cluster_list_test()
{
	std::vector<std::string> vow_list = {"a", "i", "u", "e", "o"};
	std::vector<int> placement_flags = {6, 6, 3, 6, 1};
	ClusterInfo vowel_info { vow_list, placement_flags };
	return vowel_info;
}
