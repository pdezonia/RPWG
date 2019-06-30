#include "cluster_info.h"
#include "language_info.h"

#include <iostream>
#include <string>
#include <vector>

// Forward declare functions
LanguageInfo load_language(std::string target_language);

int main() {
	std::cout << "Testing cluster loader\n";

	std::string user_lang_code;
	std::cout << "Input a language code: ";
	std::cin >> user_lang_code;

	std::cout << "\n" << "entered: " << user_lang_code << "\n";

	LanguageInfo user_lang_info;
	user_lang_info = load_language(user_lang_code);
}
