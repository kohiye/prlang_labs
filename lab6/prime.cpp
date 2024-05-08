#include <cmath>
#include <iostream>

bool isPrime(int number) {
  if (number < 2)
    return false;

  for (int i{2}; i <= std::sqrt(number); ++i) {
    if (number % i == 0)
      return false;
  }
  return true;
}

void primeOut(int a, int b) {
  for (int i{a}; i <= b; ++i) {
    if (isPrime(i))
      std::cout << i << ' ';
  }
}

void primePairOut(int a, int b) {
  int prev{};
  for (int i{a}; i <= b; ++i) {
    if (isPrime(i)) {
      if (prev && (i == (prev + 2))) {
        std::cout << prev << ' ' << i << '\n';
      }
      prev = i;
    }
  }
}

int main() {
  int a{};
  std::cin >> a;
  int b{};
  std::cin >> b;
  std::cout << "Primes: ";
  primeOut(a, b);
  std::cout << "\nPairs: ";
  primePairOut(a, b);
  return 0;
}
