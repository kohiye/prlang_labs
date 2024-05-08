#include <iostream>

int numOfDigits(int num) {
  int count{};
  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}

int main() {
  int n{};
  std::cin >> n;
  int m{};
  std::cin >> m;
  int num_n = numOfDigits(n);
  int num_m = numOfDigits(m);
  if (num_n < num_m)
    std::cout << m << " has more digits than " << n << std::endl;
  else if (num_n > num_m)
    std::cout << n << " has more digits than " << m << std::endl;
  else
    std::cout << "same amount of digits" << std::endl;

  return 0;
}
