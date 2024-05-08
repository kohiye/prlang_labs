#include <chrono>
#include <iostream>
#include <random>
#include <vector>

namespace randMT {
std::mt19937 mt{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count())};
}

int randomIndex(int size) {
  std::uniform_int_distribution randomIndex{0, size - 1};
  return randomIndex(randMT::mt);
}

void printName(const std::vector<std::string> &f_names,
               const std::vector<std::string> &l_names, int times) {
  int fNamesSize = f_names.size();
  int lNamesSize = l_names.size();
  while (times > 0) {
    std::cout << f_names[randomIndex(fNamesSize)] << ' ';
    std::cout << l_names[randomIndex(lNamesSize)] << '\n';
    --times;
  }
}

int main() {
  std::vector<std::string> f_names{"Jorhe", "John", "Pablo", "Fred", "Kim"};
  std::vector<std::string> l_names{"Smitt", "De'Guzman", "Johns"};
  printName(f_names, l_names, 10);

  return 0;
}
