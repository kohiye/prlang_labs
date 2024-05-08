#include <fstream>
#include <iostream>

int main() {

  std::ifstream inFile("threeNumbers.txt");

  int tempNum{};
  int minPositive{0x7F'FF'FF'FF};

  while (inFile >> tempNum) {
    if (tempNum > 0 && tempNum < minPositive)
      minPositive = tempNum;
  }

  std::cout << minPositive << '\n';

  return 0;
}
