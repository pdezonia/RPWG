#include "language_info.h"
#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/* word_builder.cpp Takes information about a desired language and an
 * approximate desired word length and returns a random pronounceable
 * word.
 */

using namespace std;

string word_builder(LanguageInfo lang_info, int word_len) {
	// Seed random number generator
	srand(time(0));
	// Unpack language struct
	ClusterInfo con_cluster_info = lang_info.consonant_cluster_info;
	ClusterInfo vow_cluster_info = lang_info.vowel_cluster_info;
	// Ignoring substring replacement for now
	
	// Unpack cluster structs
	// First consonant clusters
	vector<string> con_list = con_cluster_info.character_clusters;
	vector<vector<int>> con_rules =	con_cluster_info.placement_flags;
	// Then vowel clusters
	vector<string> vow_list = vow_cluster_info.character_clusters;
	vector<vector<int>> vow_rules = vow_cluster_info.placement_flags;

	// Note number of clusters for vowels and consonants
	int total_amt_vow_clusters = con_list.size();
	int total_amt_con_clusters = vow_list.size();
	
	// Randomly choose whether to start with a consonant or vowel cluster
	// a 1 means start with a vowel and 0 means start with a consonant
	int last_clust_was_vowel = rand() % 2;
	
	string temp_return_string = "test finished";
	return temp_return_string;
}
