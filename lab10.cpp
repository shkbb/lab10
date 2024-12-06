#include <iostream>
#include <regex>
#include <string>

void findDuplicates(const std::string& input) {
    std::regex duplicateRegex(R"((\w)\1)"); 
    std::smatch match;

    std::string temp = input;
    bool found = false;

    std::cout << "Duplicates found in the string \"" << input << "\":\n";

    while (std::regex_search(temp, match, duplicateRegex)) {
        std::cout << match.str() << std::endl;
        temp = match.suffix().str();
        found = true;
    }

    if (!found) {
        std::cout << "No duplicates found.\n";
    }
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    findDuplicates(input);

    return 0;
}
