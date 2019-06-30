#include "cluster_info.h"
#include "language_info.h"

#include <iostream>
#include <string>
#include <vector>

/* cluster_loader.cpp Takes a lowercase string indicating desired language
 * style to use for word generation. Then returns a language struct containing
 * a list of vowel clusters, consonant clusters, and substring swaps. */

// Forward declare functions used
ClusterInfo con_cluster_list_test();
ClusterInfo vow_cluster_list_test();

LanguageInfo load_language(std::string target_language) 
{
	// Define languge styles available
	std::string test_lang_code = "test";
	std::string jp_lang_code = "japanese";

	LanguageInfo language_settings;

	if(target_language == test_lang_code) 
	{
		// NOTE Currently not defining replacement list
		language_settings.consonant_cluster_list = 
						con_cluster_list_test();
		language_settings.vowel_cluster_list = 
						vow_cluster_list_test();
	}
	else if(target_language == jp_lang_code)
       	{
		std::cout << "Language in progress\n";
	}
	else
	{
		std::cout << "Code not recognized.\n";
	}

	return language_settings;
}


