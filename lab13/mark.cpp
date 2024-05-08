#include <chrono>
#include <iostream>
#include <random>
#include <vector>

namespace randShot {
std::mt19937 mt{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count())};

std::uniform_int_distribution shot{0, 10};
} // namespace randShot

void shoot(std::vector<std::vector<int>> &marks) {
  for (int n{0}; n < marks.size(); ++n) {
    for (int m{0}; m < marks[0].size(); ++m) {
      marks[n][m] = randShot::shot(randShot::mt);
      std::cout << marks[n][m] << ' ';
    }
    std::cout << std::endl;
  }
};

void findWinner(std::vector<std::vector<int>> &marks) {
  std::vector<int> totals(marks.size(), 2);
  for (int n{0}; n < marks.size(); ++n) {
    int count{};
    for (int m{0}; m < marks[0].size(); ++m) {
      count += marks[n][m];
    }
    totals[n] = count;
  }

  // tops
  int max{totals[0]};
  for (int n{1}; n < totals.size(); ++n) {
    if (totals[n] > max)
      max = totals[n];
  }
  for (int n{1}; n < totals.size(); ++n) {
    if (totals[n] == max) {
      std::cout << "Player #" << n << " has won!\n";
    }
  }
}

int main() {

  constexpr int n{7};
  constexpr int m{8};
  std::vector<std::vector<int>> marks(n, std::vector<int>(m, false));

  shoot(marks);
  findWinner(marks);

  return 0;
}
