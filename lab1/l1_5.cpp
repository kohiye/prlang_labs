#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  double y, a, omg, x, phi;
  const double PI = 3.141593;
  std::cout << "Input a: ";
  std::cin >> a;
  std::cout << "Input \u03c9: ";
  std::cin >> omg;
  std::cout << "Input \u03c6: ";
  std::cin >> phi;
  x = PI / 2.0 - phi;
  y = a * std::exp(-a * omg * x) * std::sin(omg * x);
  std::cout << "y = " << y << std::endl;
  return 0;
}
