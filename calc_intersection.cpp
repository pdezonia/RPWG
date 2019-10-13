#include "rpwg_fwd_dec.h"

#include <iostream>
#include <string>
#include <vector>

/* calc_intersection.cpp Takes two vectors of integers or arbitrary length and
 * returns a vector of integers that exist in both vectors. Note both input
 * vectors must be sorted and not contain duplicates.
 */

using namespace std;

vector<int> calc_intersection(vector<int> vec_1, vector<int> vec_2) {
    // Initialize return vector
    vector<int> intersection_vec;
    // Initialize index trackers for each input vector
    int ind_1 = 0;
    int ind_2 = 0;

    // Get lengths of each input vector
    int len_1 = vec_1.size();
    int len_2 = vec_2.size();

    while(ind_1 < len_1 and ind_2 < len_2) {
        // cout << ind_1 << " " << ind_2 << "\n";
        if(vec_1[ind_1] < vec_2[ind_2]) {
            ind_1++;
        } else if (vec_1[ind_1] > vec_2[ind_2]) {
            ind_2++;
        } else {
            intersection_vec.push_back(vec_1[ind_1]);
            ind_1++;
            ind_2++;
        }
    }

    return intersection_vec;
}