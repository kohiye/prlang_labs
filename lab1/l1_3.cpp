#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  double s, p, a, b, c, h_a, h_b, h_c;
  std::cout << "Input a: ";
  std::cin >> a;
  std::cout << "Input b: ";
  std::cin >> b;
  std::cout << "Input c: ";
  std::cin >> c;
  p = (a + b + c) / 2.0;
  s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  h_a = 2 * s / a;
  h_b = 2 * s / b;
  h_c = 2 * s / c;
  std::cout << "h_a = " << h_a << std::endl;
  std::cout << "h_b = " << h_b << std::endl;
  std::cout << "h_c = " << h_c << std::endl;
  return 0;
}
