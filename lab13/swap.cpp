#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using matrix = std::vector<std::vector<int>>;

namespace randVals {
std::mt19937 mt{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count())};

int get(int a, int b) { return std::uniform_int_distribution{a, b}(mt); }
} // namespace randVals

void drawMatrix(matrix &Mtrx) {
  for (uint i{0}; i < Mtrx.size(); ++i) {
    for (uint j{0}; j < Mtrx.size(); ++j) {
      std::cout << Mtrx[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
void fillMatrix(matrix &Mtrx, int a, int b) {
  for (uint i{0}; i < Mtrx.size(); ++i) {
    for (uint j{0}; j < Mtrx.size(); ++j) {
      Mtrx[i][j] = randVals::get(a, b);
    }
  }
}

void swapMinMax(matrix &Mtrx) {
  int maxNeg{-999999};
  int minPos{999999};
  int *maxRef = &maxNeg;
  int *minRef = &minPos;
  for (uint i{0}; i < Mtrx.size(); ++i) {
    for (uint j{0}; j < Mtrx.size(); ++j) {
      if (j > i && j < (Mtrx.size() - i)) {
        if (Mtrx[i][j] < 0 and Mtrx[i][j] > *maxRef) {
          maxRef = &Mtrx[i][j];
        }
      }
      if (j < i && j > (Mtrx.size() - i)) {
        if (Mtrx[i][j] > 0 and Mtrx[i][j] < *minRef) {
          minRef = &Mtrx[i][j];
        }
      }
    }
  }
  std::cout << "max " << *maxRef << " min " << *minRef << '\n';
  int temp = *maxRef;
  *maxRef = *minRef;
  *minRef = temp;
}
int main() {
  constexpr int n{10};
  constexpr int m{10};
  constexpr int a{-12415};
  constexpr int b{12415};

  matrix startMtrx(n, std::vector<int>(m, false));
  fillMatrix(startMtrx, a, b);
  drawMatrix(startMtrx);
  swapMinMax(startMtrx);
  std::cout << "After:" << std::endl;
  drawMatrix(startMtrx);
  return 0;
}
