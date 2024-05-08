#include <iostream>
#include <vector>

bool isEshelon(std::vector<std::vector<double>> &A) {
  for (int i{0}; i < A.size(); ++i) {
  }
};

void elimination(std::vector<std::vector<double>> &A) {
  do {
    int diagIndex = 0;
    while (diagIndex < A.size()) {

      int cRow = diagIndex;
      int cCol = diagIndex;

      int rowIndex = cRow + 1;
      while (rowIndex < A.size()) {
        double rowOneValue = A[cCol][cCol];
        if (rowOneValue != 0) {
          ++rowIndex;
          continue;
        }
        double cElementValue = A[rowIndex][cCol];
        double correctionFactor = -(cElementValue / rowOneValue);

        for (int i{0}; i < A[rowIndex].size(); ++i) {
          A[rowIndex][i] += (A[rowIndex][i] * correctionFactor);
        }
        ++rowIndex;
      }
    }
  } while (!isEshelon(A));
}

int main() {

  std::vector<std::vector<double>> A = {{2, 3, -1}, {4, 1, 2}, {-3, 2, 3}};
  elimination(A);

  return 0;
}
