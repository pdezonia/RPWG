#include "rpwg_fwd_dec.h"

#include <iostream>
#include <string>
#include <vector>

/* filter_by_freq.cpp Takes a vector of frequency scores and a dice roll and
   and returns a list of indices in the frequency score vector where the 
   frequency scores are greater than or equal to the dice roll.
 */

using namespace std;

vector<int> filter_by_freq(vector<int> scores, int dice_roll) 
{
    // Get number of frequency scores we are given to filter
    int num_scores = scores.size();
    // Initialize return vector, will add values to it in loop
    vector<int> indices;

    for(int score_ind = 0; score_ind < num_scores; score_ind++) 
    {
        int found_val = scores[score_ind];
        if(found_val >= dice_roll)
        {
            indices.push_back(score_ind);
        }
    }

    return indices;
}
