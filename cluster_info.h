#ifndef CLUSTER_INFO_H
#define CLUSTER_INFO_H

#include <vector>
#include <string>

struct ClusterInfo {
	// Vector of strings of consonants or vowels that can appear together
	// in a word
	std::vector<std::string> character_clusters;
	// 2-D vector of ints. Row i corresponds to a cluster at index i in
	// the character cluster vector. A 1 in the first column of row i
	// means that cluster i is allowed to occur at the beginning of a word,
	// a 1 in the second column means that the cluster can occur in the 
	// middle of the word, and a 1 in column three means that the cluster
	// can occur at the end of the word. 0s mean that they cannot occur at
	// those positions.
	std::vector<std::vector<int>> placement_flags;
};

#endif
