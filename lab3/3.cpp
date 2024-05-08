#include <cmath>
#include <iostream>
#include <iterator>

int main(int argc, char *argv[]) {
  int a, b, c, t, h, c1, c2;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  if (!(a + b > c && a + c > b && b + c > a)) {
    std::cout << "UNDEFINED" << std::endl;
    return 1;
  }
  if (a > b && a > c) {
    h = a;
    c1 = b;
    c2 = c;
  } else if (b > c && b > a) {
    h = b;
    c1 = a;
    c2 = c;
  } else {
    h = c;
    c1 = a;
    c2 = b;
  }
  t = std::sqrt(std::pow(c1, 2) + std::pow(c2, 2));
  if (t == h) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
