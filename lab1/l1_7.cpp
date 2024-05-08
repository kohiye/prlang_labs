#include <iostream>

int main(int argc, char *argv[]) {
  double num;
  int dig;
  std::cout << "Enter a decemal fraction: ";
  std::cin >> num;
  dig = int(num * 10) % 10;
  std::cout << "result: " << dig << std::endl;
  return 0;
}
