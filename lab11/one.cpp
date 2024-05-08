#include <iostream>

int main() {
  int number{};
  int *ptr{&number};
  *ptr = 100;
  int *ptr2 = ptr;
  *ptr2 = 200;

  std::cout << "*ptr: " << *ptr << '\n';
  std::cout << "*ptr2: " << *ptr2 << '\n';
  return 0;
}
