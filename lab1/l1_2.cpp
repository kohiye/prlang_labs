#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  double s, p, a, b, c;
  std::cout << "Input a: ";
  std::cin >> a;
  std::cout << "Input b: ";
  std::cin >> b;
  std::cout << "Input c: ";
  std::cin >> c;
  p = (a + b + c) / 2.0;
  s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  std::cout << "s = " << s << std::endl;
  return 0;
}
