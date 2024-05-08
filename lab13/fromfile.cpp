#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>

using vector = std::vector<double>;
using namespace std::string_view_literals;
using matrix = std::vector<std::vector<double>>;

double findExpr(int m, int n, matrix &A, matrix &C, vector &B, vector &D) {
  return 10 * A[m][n] * B[m] - C[m][n] * D[m];
}

matrix readMatrix(std::string_view &filename) { return filename; }

int main() {
  matrix Af = readMatrix("Amatrix.txt"sv);
  matrix A = {{{23.523, -4.423, -1.342},
               {4.234, -8.444, 2.222},
               {1.222, 9.234, -6.731}}};
  matrix C = {{{-3.523, 5.423, -1.342},
               {2.248, -1.444, 2.200},
               {-1.992, 3.234, 6.731}}};
  vector B{0.235, 2.235, 5.235};
  vector D{3.251, 2.259, -2.320};

  return 0;
}
