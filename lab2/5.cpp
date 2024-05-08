#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string fname, lname, age;
  std::cout << "What's your first name? ";
  std::getline(std::cin, fname);
  std::cout << "What's your last name? ";
  std::cin >> lname;
  std::cout << "What's your age? ";
  std::cin >> age;
  std::cout << "Name: " << lname << ", " << fname << "\n";
  std::cout << "Age: " << age << std::endl;
  return 0;
}
