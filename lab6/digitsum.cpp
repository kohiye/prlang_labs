#include <iostream>

int sumOfDigits(int num) {
  int sum{0};
  while (num > 0) {
    int digit{num % 10};
    sum += digit;
    num /= 10;
  }
  return sum;
}

int main() {
  int n{};
  std::cin >> n;
  int great{};
  int least{};
  for (int i{1}; i <= n; ++i) {
    int number{};
    std::cin >> number;
    int digits{sumOfDigits(number)};
    if (!great || digits > great)
      great = digits;
    if (!least || digits < least)
      least = digits;
  }
  std::cout << "Great: " << great << '\n';
  std::cout << "Least: " << least << '\n';

  return 0;
}
