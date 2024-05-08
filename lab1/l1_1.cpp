#include <cmath>
#include <iostream>

int main() {
  double y, x_1, x_2;
  std::cout << "Input x_1: ";
  std::cin >> x_1;
  std::cout << "Input x_2: ";
  std::cin >> x_2;
  y = (std::exp(-x_1) + std::exp(-x_2)) / 2.0;
  std::cout << y << std::endl;
  return 0;
}
