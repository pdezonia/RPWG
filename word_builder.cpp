#include "language_info.h"
#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>

std::vector<std:string>> word_builder(LanguageInfo lang_info, int word_len) {
	// Unpack language struct
	ClusterInfo con_cluster_info = lang_info.consonant_cluster_info;
	ClusterInfo vow_cluster_info = lang_info.vowel_cluster_info;
	// Ignoring substring replacement for now
	
	// Unpack cluster structs
	std::vector<std::string>> con_list = 
				con_cluster_info.character_clusters;
	std::vector<std::vector<int>> con_rules = 
				con_cluster_info.placement_flags;

	std::vector<std::string>> vow_list = 
				vow_cluster_info.character_clusters;
	std::vector<std::vector<int>> = vow_rules = 
				vow_cluster_info.placement_flags;

	// Note number of clusters for vowels and consonants

}
