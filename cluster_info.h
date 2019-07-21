#ifndef CLUSTER_INFO_H
#define CLUSTER_INFO_H

#include <vector>
#include <string>

struct ClusterInfo {
	// Vector of strings of consonants or vowels that can appear together
	// in a word
	std::vector<std::string> character_clusters;	
	// A vector of ints. Row i corresponds to the cluster at index i in
	// the character cluster vector. 
	// A 0 indicates that the cluster goes at the beginning of a word only. 
	// A 1 indicates that the cluster goes at the middle of a word only. 
	// A 2 indicates that the cluster goes at the end of a word only. 
	// A 3 indicates that the cluster goes at the beginning and middle 
	//   of a word. 
	// A 4 indicates that the cluster goes at the beginning and end 
	//   of a word. 
	// A 5 indicates that the cluster goes at the middle and end of a word.
	// A 6 indicates that the cluster can appear at any part of the word.
	std::vector<int> placement_flags;
};

#endif
