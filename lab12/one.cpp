#include <fstream>
#include <iostream>

int main() {
  std::cout << "Enter n: ";
  int n{};
  std::cin >> n;
  std::ofstream evenOutFile("numbers.txt");

  for (int i{2}; i <= 2 * n; i += 2) {
    evenOutFile << i << '\n';
  }

  evenOutFile.close();

  std::cout << "Enter m: ";
  int m{};
  std::cin >> m;

  std::ifstream evenInFile("numbers.txt");

  std::cout << "Numbers: \n";

  for (int i{0}; i < m; ++i) {
    int num{};
    evenInFile >> num;
    std::cout << num << ' ';
  }

  evenInFile.close();

  return 0;
}
