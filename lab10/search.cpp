#include <algorithm>
#include <iostream>
#include <vector>

// Function to check if a string contains the search string
bool containsSearchString(const std::string &str,
                          const std::string &searchString) {
  return str.find(searchString) != std::string::npos;
}

int main() {
  std::vector<std::string> strings;
  std::string inputString;

  std::cout << "strings: " << std::endl;
  while (true) {
    std::getline(std::cin, inputString);
    if (inputString.empty()) {
      break;
    }
    strings.push_back(inputString);
  }

  std::string searchString;
  std::cout << "search string: ";
  std::getline(std::cin, searchString);

  std::cout << "strings containing '" << searchString << "':" << std::endl;
  for (const auto &str : strings) {
    if (containsSearchString(str, searchString)) {
      std::cout << str << std::endl;
    }
  }

  return 0;
}
