#include "language_info.h"
#include "cluster_info.h"
#include "rpwg_fwd_dec.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/* get_cluster.cpp Takes a cluster struct, vowel or consonant, and a 0-2 int
 * designating whether a cluster belonging to the beginning, middle, or end
 * of a word and returns a single cluster randomly chosen the belongs in the 
 * correct part of the word.
 *
 * clust_type is either 0, 1, or 2. 0 indicates that a cluster for the 
 * beginning of a word is needed, 1 is for a middle cluster, and 2 is for
 * an ending cluster.
 */

using namespace std;


string get_cluster(ClusterInfo clust_info, int cluster_type, int rng_seed) {
    // Declare dice number of sides
    int dice_max = 10;

    // Seed random number generator for choosing clusters out of a list
    srand(rng_seed);
	// Unpack cluster struct
	vector<string> char_clust_vect = clust_info.character_clusters;
	vector<int> placement_flags = clust_info.placement_flags;
    vector<int> frequency_scores = clust_info.frequency_scores;

	// Test getting an index list
	/*
	vector<int> middle_flags = {1, 3, 5, 6};
	vector<int> index_list = find_indices(placement_flags, middle_flags);
	cout << "Testing index finder: \n";
	cout << index_list[0] << ", " << index_list[1] << "\n";
	*/

	// Get flag codes
	vector<int> target_flags;
	target_flags = get_flag_codes(cluster_type);

	// Get list of indices with clusters of position type demanded by
	// calling function
	vector<int> inds_by_pos = find_indices(placement_flags, target_flags);

    // Get list of indices of clusters with frequency score in excess of
    // dice roll
    int dice_roll = (rand() % (dice_max - 1)) + 1;
    vector<int> inds_by_freq = filter_by_freq(frequency_scores, dice_roll);

    // cout << frequency_scores.size() << "\n";
    // cout << dice_roll << inds_by_freq.size() << "\n";

    // Calculate intersection of two lists to determine which clusters we
    // can pick from
    vector<int> final_inds = calc_intersection(inds_by_pos, inds_by_freq);
    // cout << final_inds[0] << "\n";

	// Randomly choose entry from resulting list
	int num_of_potential_clusts = final_inds.size();
	int meta_ind = (rand() % num_of_potential_clusts);
	string return_cluster = char_clust_vect[final_inds[meta_ind]];
	return return_cluster;
}
