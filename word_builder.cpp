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

// Forward declare functions used
string get_cluster(ClusterInfo clust_info, int clust_type, int rng_seed);
string choose_cluster(LanguageInfo lang_info, int want_vowel, int clust_pos, 
					  int rng_seed);


string word_builder(LanguageInfo lang_info, int word_len, int rng_seed) {
	// Seed random number generator
	srand(rng_seed);
	// Unpack language struct
	ClusterInfo con_cluster_info = lang_info.consonant_cluster_info;
	ClusterInfo vow_cluster_info = lang_info.vowel_cluster_info;
	// Ignoring substring replacement for now
	//
	
	// Unpack cluster structs
	// First consonant clusters
	vector<string> con_list = con_cluster_info.character_clusters;
	vector<int> con_rules =	con_cluster_info.placement_flags;
	// Then vowel clusters
	vector<string> vow_list = vow_cluster_info.character_clusters;
	vector<int> vow_rules = vow_cluster_info.placement_flags;

	// Note number of clusters for vowels and consonants
	int total_amt_vow_clusters = con_list.size();
	int total_amt_con_clusters = vow_list.size();
	
	// Randomly choose whether to start with a consonant or vowel cluster
	// a 1 means start with a vowel and 0 means start with a consonant
	int first_clust_is_vowel = rand() % 2;
	
	// Randomly choose whether to end with a consonant or vowel cluster
	int final_clust_is_vowel = rand() % 2;

	// Determine whether desired word length is even or odd
	int word_len_even = 1 - (word_len % 2);

	// Decide whether to take off a cluster to satisfy word start and end
	// constraints with regards to vowel vs consonant
	int sv = first_clust_is_vowel;
	int ev = final_clust_is_vowel;
	int el = word_len_even;
	// Note that this expression is always either 0 or 1 provided that 
	// sv, ev, and el are each either 0 or 1
	int clusts_to_take_off = 1 - ((1 - abs((1 - sv) - el)*ev)
			 	     *(1 - abs(sv - el)*(1 - ev)));
	int loop_length = word_len - clusts_to_take_off;
	
	// Set the code for cluster position
	int cluster_pos = 0;
	string return_word = choose_cluster(lang_info, first_clust_is_vowel, 
					    cluster_pos, rand());

	// Create flag indicating whether the next desired cluster should be
	// a vowel
	int use_vowel = 1 - first_clust_is_vowel;
	cluster_pos = 1;
	for (int i = 0; i <= loop_length - 2; i++) {
		return_word += choose_cluster(lang_info, use_vowel,
			       		      cluster_pos, rand());
		use_vowel = 1 - use_vowel;
	}

	// Add final cluster
	cluster_pos = 2;
	return_word += choose_cluster(lang_info, use_vowel, cluster_pos, rand());

	return return_word;
}
