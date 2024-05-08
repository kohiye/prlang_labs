#include <iostream>

int main(int argc, char *argv[]) {
  int celc;
  std::cout << "Input temperature in Celcius: ";
  std::cin >> celc;
  std::cout << celc << " degrees Celcius equals " << int(1.8 * celc + 32)
            << " degrees Fahrenheit." << std::endl;
  return 0;
}
