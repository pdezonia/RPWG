#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>

/* cluster_list_tester.cpp
 * Script for testing/practicing vectors, lists, structs, and multi-file
 * programs.*/

// Forward declare cluster list function
ClusterInfo con_cluster_list_test();
ClusterInfo vow_cluster_list_test();

int main() {
	std::cout << "Testing cluster lists.\n";

	ClusterInfo consonant_info = con_cluster_list_test();
	ClusterInfo vowel_info = vow_cluster_list_test();
	
	// Unpack consonant clusters and placement array
	std::vector<std::string> con_list = consonant_info.character_clusters;
	std::vector<std::vector<int>> consonant_flag_list = 
					consonant_info.placement_flags;

	// Unpack vowel clusters and placement array
	std::vector<std::string> vow_list = vowel_info.character_clusters;
	std::vector<std::vector<int>> vowel_flag_list = 
					vowel_info.placement_flags;

	std::cout << "First consonant entry: " << con_list[0] << "\n";
	std::cout << "First vowel entry: " << vow_list[0] << "\n";


	std::cout << "Done\n";
	return 0;
}
