#include "language_info.h"
#include "cluster_info.h"
#include "rpwg_fwd_dec.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* generate_words.cpp Gets language info from two cluster files and generates N
 * random pronounceable words from the desired language.
 */

using namespace std;


int main() 
{
    // Declare number of words to generate
    int num_words = 10;
    // Declare target word length as number of clusters
    int word_len = 5;

    // Seed random number generator
    srand(time(0));

    // State names of files to extract language information from
    string con_file = "youmen_con.txt";
    string vow_file = "youmen_vow.txt";

    // Create receptical cluster info structs 
    ClusterInfo con_clust;
    ClusterInfo vow_clust;
    // Create receptical language info struct
    LanguageInfo lang_info;
    // Create receptical string for word builder output
    string new_word;

    // Read from files
    con_clust = file_reader(con_file);
    vow_clust = file_reader(vow_file);
    // Pack language info struct
    lang_info.consonant_cluster_info = con_clust;
    lang_info.vowel_cluster_info = vow_clust;


    // Test filter_by_freq
    // vector<int> filtered_inds;
    // vector<int> list_1 = {1, 2, 3, 4, 5, 5};
    // int dice_roll = 3;
    // filtered_inds = filter_by_freq(list_1, dice_roll);
    // cout << filtered_inds[0] << filtered_inds[1] << filtered_inds[2] << "\n";

    // return 0;


    // Generate words repeatedly
    for(int i = 0; i < num_words; i++) 
    {
        new_word = word_builder(lang_info, word_len, rand());
        cout << new_word << "\n";
    }

    // return 0;
}