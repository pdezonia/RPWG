#include <iostream>
#include <string>
#include <vector>

/*cluster_list_tester.cpp
 * Script for testing/practicing vectors, lists, structs, and multi-file
 * programs.*/

// Forward declare cluster list function
std::vector<std::string> con_cluster_list_test();

int main() {
	std::cout << "Testing cluster loader.\n";

	std::vector<std::string> con_list = con_cluster_list_test();

	std::cout << "First consonant entry: " << con_list[0] << "\n";


	std::cout << "Done\n";
	return 0;
}
