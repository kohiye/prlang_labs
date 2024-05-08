#include <iostream>

int main(int argc, char *argv[]) {
  int num;
  std::cout << "Enter a five digit number: ";
  std::cin >> num;
  std::cout << "First digit: " << num / 10000 << "\n";
  std::cout << "Second digit: " << (num % 10000) / 1000 << "\n";
  std::cout << "Third digit: " << (num % 1000) / 100 << "\n";
  std::cout << "Forth digit: " << (num % 100) / 10 << "\n";
  std::cout << "Fifth digit: " << num % 10 << std::endl;
  return 0;
}
