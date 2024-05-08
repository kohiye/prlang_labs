#include <iostream>
#include <vector>

using namespace std;

const double EPSILON =
    1e-10; // Small value to handle floating-point precision issues

// Perform Gaussian elimination to solve a system of linear equations
vector<double> solveSystem(vector<vector<double>> &A, vector<double> &B) {
  int n = A.size();

  // Forward elimination
  for (int i = 0; i < n; ++i) {
    // Find the pivot row
    int pivotRow = i;
    for (int j = i + 1; j < n; ++j) {
      if (abs(A[j][i]) > abs(A[pivotRow][i])) {
        pivotRow = j;
      }
    }

    // Swap rows if necessary
    if (pivotRow != i) {
      swap(A[i], A[pivotRow]);
      swap(B[i], B[pivotRow]);
    }

    // Make the diagonal element 1
    double pivot = A[i][i];
    if (abs(pivot) < EPSILON) {
      cerr << "No unique solution exists." << endl;
      exit(1);
    }

    for (int j = i; j < n; ++j) {
      A[i][j] /= pivot;
    }
    B[i] /= pivot;

    // Eliminate other rows
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        double factor = A[j][i];
        for (int k = i; k < n; ++k) {
          A[j][k] -= factor * A[i][k];
        }
        B[j] -= factor * B[i];
      }
    }
  }

  return B;
}

int main() {
  // Example system of linear equations:
  // 2x + 3y - z = 1
  // 4x + y + 2z = -2
  // -3x + 2y + 3z = 3

  vector<vector<double>> A = {{2, 3, -1}, {4, 1, 2}, {-3, 2, 3}};

  vector<double> B = {1, -2, 3};

  vector<double> solution = solveSystem(A, B);

  // Display the solution
  cout << "Solution:" << endl;
  for (size_t i = 0; i < solution.size(); ++i) {
    cout << "x" << i + 1 << " = " << solution[i] << endl;
  }

  return 0;
}
