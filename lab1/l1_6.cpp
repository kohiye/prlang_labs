#include <iostream>

int main(int argc, char *argv[]) {
  long num, dig;
  std::cout << "Enter an integer (at lest 3 digits): ";
  std::cin >> num;
  dig = (num % 1000) / 100;
  std::cout << "result: " << dig << std::endl;
  return 0;
}
