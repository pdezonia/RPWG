#include "language_info.h"
#include "cluster_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* generate_words.cpp Gets language info from two cluster files and generates N
 * random pronounceable words from the desired language.
 */

using namespace std;

// Forward declare functions
string word_builder(LanguageInfo, int);
ClusterInfo file_reader(string file_name);

int main() {
    // Declare number of words to generate
    int num_words = 5;
    // Declare target word length as number of clusters
    int word_len = 5;

    // State names of files to extract language information from
    string con_file = "japn_simple_con.txt";
    string vow_file = "japn_simple_vow.txt";

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

    // Generate words repeatedly
    for(int i = 0; i < num_words; i++) {
        new_word = word_builder(lang_info, word_len);
        cout << new_word << "\n";
    }

    return 0;
}