#ifndef LANGUAGE_INFO_H
#define LANGUAGE_INFO_H

#include "cluster_info.h"

#include <vector>
#include <string>

struct LanguageInfo 
{
	ClusterInfo consonant_cluster_info;
	ClusterInfo vowel_cluster_info;
	// 2-D array of substrings, first column is a list of substrings 
	// that should not appear in the given language, the second column
	// is a list of substrings that shall replace them.
	std::vector<std::vector<std::string>> substring_replacement;
};

#endif
