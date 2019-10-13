#ifndef RPWG_FWD_DEC_H
#define RPWG_FWD_DEC_H

#include "language_info.h"
#include "cluster_info.h"

#include <string>
#include <vector>

using namespace std;

// Fowrward declare all functions used
ClusterInfo file_reader(string file_name);
vector<string> string_splitter(string chunk, char delimiter);
string word_builder(LanguageInfo lang_info, int word_len, int rng_seed);
string choose_cluster(LanguageInfo lang_info, int want_vowel, int clust_pos, 
                      int rng_seed);
string get_cluster(ClusterInfo clust_info, int cluster_type, int rng_seed);
vector<int> find_indices(vector<int> flag_vect, vector<int> target_inds);
vector<int> filter_by_freq(vector<int> scores, int dice_roll);
vector<int> get_flag_codes(int cluster_type);
vector<int> calc_intersection(vector<int> vec_1, vector<int> vec_2);
#endif