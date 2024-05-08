#include <cctype>
#include <iostream>
#include <string>

bool checkLen(std::string &input) {
  return (input.length() >= 8) && (input.length() <= 14);
}
bool checkASCII(std::string &input) {
  for (char ch : input) {
    if (!(ch >= 33) || !(ch <= 126))
      return false;
  }
  return true;
}
bool hasUpper(std::string &str) {
  for (char ch : str) {
    if (std::isupper(ch))
      return true;
  }
  return false;
}
bool hasLower(std::string &str) {
  for (char ch : str) {
    if (std::islower(ch))
      return true;
  }
  return false;
}
bool hasDigit(std::string &str) {
  for (char ch : str) {
    if (std::isdigit(ch))
      return true;
  }
  return false;
}
bool hasSym(std::string &str) {
  for (char ch : str) {
    if (!std::isalnum(ch))
      return true;
  }
  return false;
}
bool checkDivers(std::string &input) {
  return (hasSym(input) + hasDigit(input) + hasLower(input) + hasUpper(input) >=
          3);
}

bool checkPass(std::string &input) {
  return checkLen(input) && checkASCII(input) && checkDivers(input);
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::cout << checkPass(input) << std::endl;
  return 0;
}
