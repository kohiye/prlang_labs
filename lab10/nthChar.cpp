#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> strings;
  std::string inputString;

  std::cout << "strings:" << std::endl;
  while (true) {
    std::getline(std::cin, inputString);
    if (inputString.empty()) {
      break;
    }
    strings.push_back(inputString);
  }

  int n;
  std::cout << "char index+1 : ";
  std::cin >> n;

  for (const auto &str : strings) {
    if (n > 0 && n <= static_cast<int>(str.size())) {
      std::cout << str[n - 1] << std::endl;
    }
  }
  return 0;
}
