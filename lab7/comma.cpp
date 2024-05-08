#include <iostream>
#include <string>

std::string removeCommas(std::string &startStr) {
  std::string transform;
  for (char ch : startStr) {
    if (ch != ',')
      transform += ch;
  }
  return transform;
}

int main() {
  std::string startStr;
  std::getline(std::cin, startStr);
  std::string endStr = removeCommas(startStr);
  std::cout << endStr;
  return 0;
}
