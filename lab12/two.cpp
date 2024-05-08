#include <fstream>
#include <iostream>

int main() {
  std::ifstream inFile("numbers.txt");

  int sumOfEvens{0};
  int tempNum{};

  while (inFile >> tempNum) {
    if (tempNum % 2 == 0)
      sumOfEvens += tempNum;
  }

  std::cout << "Sum: " << sumOfEvens << '\n';

  inFile.close();

  return 0;
}
