#include <iostream>

int main(int argc, char *argv[]) {
  long double con, wrd;
  std::cout << "Enter current world population: ";
  std::cin >> wrd;
  std::cout << "Enter your country's population: ";
  std::cin >> con;
  std::cout << "Your country makes " << con / wrd * 100
            << "% of world population." << std::endl;
  return 0;
}
