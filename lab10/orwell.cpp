#include <algorithm> // For std::find
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> firstVector;
  std::vector<std::string> secondVector;
  std::string inputString;

  std::cout << "white list: " << std::endl;
  while (true) {
    std::getline(std::cin, inputString);
    if (inputString.empty()) {
      break;
    }
    firstVector.push_back(inputString);
  }

  std::cout << "searches: " << std::endl;
  while (true) {
    std::getline(std::cin, inputString);
    if (inputString.empty()) {
      break;
    }
    secondVector.push_back(inputString);
  }

  std::cout << "intersection: " << std::endl;
  for (const auto &str : secondVector) {
    if (std::find(firstVector.begin(), firstVector.end(), str) !=
        firstVector.end()) {
      std::cout << str << std::endl;
    }
  }

  return 0;
}
