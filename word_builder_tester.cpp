#include "language_info.h"
#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* word_builder_tester.cpp Tests word_builder.cpp in early development 
 * stages.
 */

using namespace std;

// Forward declare functions
ClusterInfo con_cluster_list_test();
ClusterInfo vow_cluster_list_test();
string word_builder(LanguageInfo, int);

int main() {
	int word_cluster_len = 4;

	// Constuct language information struct
	LanguageInfo test_lang_info;
	test_lang_info.consonant_cluster_info = con_cluster_list_test();
	test_lang_info.vowel_cluster_info = vow_cluster_list_test();

	string word_builder_output;

	word_builder_output = word_builder(test_lang_info, word_cluster_len);

	cout << "Word builder output is: " << word_builder_output << "\n";

	return 0;
}
