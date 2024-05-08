#include <iostream>

int factorial(int num) {
  int result{1};
  for (int i{1}; i <= num; ++i) {
    result *= i;
  }
  return result;
}

int factSum(int m, int n) {
  int sum{0};
  for (int i{m}; i <= n; ++i) {
    sum += factorial(i);
  }
  return sum;
}

int main() {
  int m{};
  std::cin >> m;
  int n{};
  std::cin >> n;
  std::cout << factSum(m, n) << std::endl;
  return 0;
}
