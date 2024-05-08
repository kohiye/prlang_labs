#include <iostream>

int main(int argc, char *argv[]) {
  int age;
  std::cout << "Enter your age in months: ";
  std::cin >> age;
  std::cout << "Your age in years: " << age / 12 << std::endl;
  return 0;
}
