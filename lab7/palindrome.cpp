#include <cctype>
#include <iostream>
#include <string>

std::string cleanUp(const std::string &str) {
  std::string cleanStr;
  for (char ch : str) {
    if (std::isalpha(ch))
      cleanStr += std::tolower(ch);
  }
  return cleanStr;
}

bool isPalindrome(const std::string &str) {
  std::string clean = cleanUp(str);
  int len = clean.length();
  for (int i{}; i < len / 2; ++i) {
    if (clean[i] != clean[len - i - 1])
      return false;
  }

  return true;
}

int main() {
  std::string input;
  std::getline(std::cin, input);

  std::cout << isPalindrome(input) << '\n';

  return 0;
}
