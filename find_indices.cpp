#include <iostream>
#include <string>
#include <vector>

/* find_indices.cpp Takes a vector of integer flags and a vector of integers
 * that are being searched for. Returns a list of indices in the flag vector
 * where the searched for integers exist.
 */

using namespace std;

vector<int> find_indices(vector<int> flag_vect, vector<int> target_ints) {
	// Get number of target ints we are searching for
	int num_targs = target_ints.size();
	// Initialize return vector, will add values to it in loop
	vector<int> indices;

	for(int flag_ind = 0; flag_ind < flag_vect.size(); flag_ind++) {
		int found_val = flag_vect[flag_ind];
		for(int targ_ind = 0; targ_ind < num_targs; targ_ind++) {
			if(found_val == target_ints[targ_ind]) {
				indices.push_back(flag_ind);
			}
		}
	}

	return indices;
}
