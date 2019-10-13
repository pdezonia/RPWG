#include "cluster_info.h"
#include "language_info.h"
#include "rpwg_fwd_dec.h"

#include <string>
#include <vector>

/* choose_cluster.cpp Given the language struct, word position, and whether
 * a consonant or vowel is desired, will return a cluster that is of the desired
 * type and belongs in the right part of the word. Note that for word positions
 * 0 is for beginning, 1 is for middle, and 2 is for end. For the 
 * vowel/consonant chooser: 1 indicates that a vowel is desired while anything 
 * else indicates that a consonant is desired.
 */

using namespace std;


string choose_cluster(LanguageInfo lang_info, int want_vowel, int clust_pos, 
					  int rng_seed) {	
	// Unpack language struct
	ClusterInfo con_cluster_info = lang_info.consonant_cluster_info;
	ClusterInfo vow_cluster_info = lang_info.vowel_cluster_info;
	
	string return_cluster;

	if(want_vowel == 1) {
		// Return vowel
		return_cluster = get_cluster(vow_cluster_info, clust_pos, rng_seed);
	} else {
		// Return consonant
		return_cluster = get_cluster(con_cluster_info, clust_pos, rng_seed);
	}

	return return_cluster;
}
