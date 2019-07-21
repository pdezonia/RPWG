#include <iostream>
#include <vector>

/* get_flag_codes.cpp Given a 0-2 int, returns a vector if ints that correspond
 * to the beginning, middle, or end of a word as specified in ClusterInfo.
 * 0 corresponds to the beginning,
 * 1 corresponds to the middle,
 * 2 corresponds to the end.
 */

using namespace std;

vector<int> get_flag_codes(int cluster_type) {
	vector<int> target_flags;
	int beginning_code = 0;
	int middle_code = 1;
	int end_code = 2;
	if(cluster_type == beginning_code) {
		target_flags = {0, 3, 4, 6};
	} else if(cluster_type == middle_code) {
		target_flags = {1, 3, 5, 6};
	} else if(cluster_type == end_code) {
		target_flags = {2, 4, 5, 6};
	} else {
		cout << "ERROR, get_flag_inds: Incorrect cluster_type.\n";
		target_flags = {-1};
	}
	return target_flags;
}
