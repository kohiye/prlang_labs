#include <fstream>
#include <iostream>

int main() {
  std::ifstream inFile("binarynumbers", std::ios::binary);

  int sumOfEvens{0};
  int tempNum{};

  while (inFile.read(*static_cast<char>(tempNum), 4)) {
    if (tempNum % 2 == 0)
      sumOfEvens += tempNum;
  }

  std::cout << "Sum: " << sumOfEvens << '\n';

  inFile.close();

  return 0;
}
