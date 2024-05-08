#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  double s, R, r, l, h, v;
  const double PI = 3.141593;
  std::cout << "Input R: ";
  std::cin >> R;
  std::cout << "Input r: ";
  std::cin >> r;
  std::cout << "Input l: ";
  std::cin >> l;
  std::cout << "Input h: ";
  std::cin >> h;
  s = PI * (R - r) * l + std::pow(R, 2) + PI * std::pow(r, 2);
  v = (1.0 / 3.0) * (std::pow(R, 2) + std::pow(r, 2) + R * r) * h * PI;
  std::cout << "s = " << s << std::endl;
  std::cout << "v = " << v << std::endl;
  return 0;
}
