#include <iostream>

int main(int argc, char *argv[]) {
  int a, b;
  std::cout << "a: ";
  std::cin >> a;
  std::cout << "b: ";
  std::cin >> b;
  if (a > 0 && b % 2 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
