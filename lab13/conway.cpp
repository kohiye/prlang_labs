#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void createCanvas(std::vector<std::vector<bool>> &canvas, uint rows, uint cols);
void drawCanvas(std::vector<std::vector<bool>> &canvas, uint rows, uint cols);
void updateCanvas(std::vector<std::vector<bool>> &canvas, uint rows, uint cols);
constexpr int countNeighbors(std::vector<std::vector<bool>> &canvas, uint rows,
                             uint cols, uint i, uint j);

int main() {
  uint rows{};
  std::cin >> rows;
  uint cols{};
  std::cin >> cols;

  std::vector<std::vector<bool>> canvas(rows, std::vector<bool>(cols, false));

  createCanvas(canvas, rows, cols);
  drawCanvas(canvas, rows, cols);

  for (int i{0}; i < 5; ++i) {
    updateCanvas(canvas, rows, cols);
    std::cout << "gen " << i << '\n';
    drawCanvas(canvas, rows, cols);
  }
  return 0;
}

void createCanvas(std::vector<std::vector<bool>> &canvas, uint rows,
                  uint cols) {
  std::srand(std::time(0));
  for (uint i{0}; i < rows; ++i) {
    for (uint j{0}; j < cols; ++j) {
      canvas[i][j] = std::rand() % 2 == 0;
    }
  }
}

void drawCanvas(std::vector<std::vector<bool>> &canvas, uint rows, uint cols) {
  for (uint i{0}; i < rows; ++i) {
    for (uint j{0}; j < cols; ++j) {
      std::cout << (canvas[i][j] ? '@' : '.') << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

constexpr int countNeighbors(std::vector<std::vector<bool>> &canvas, uint rows,
                             uint cols, int i, int j) {
  int count{};
  for (int v{i - 1}; v <= i + 1; ++v) {
    for (int h{j - 1}; h <= j + 1; ++h) {
      if (v >= 0 && v < rows && h >= 0 && h < cols) {
        if (!(v == i && h == j)) {
          count += canvas[v][h] ? 1 : 0;
        }
      }
    }
  }
  return count;
}

void updateCanvas(std::vector<std::vector<bool>> &canvas, uint rows,
                  uint cols) {
  std::vector<std::vector<bool>> updatedCanvas(rows,
                                               std::vector<bool>(cols, false));

  for (int i{0}; i < rows; ++i) {
    for (int j{0}; j < cols; ++j) {
      int count{countNeighbors(canvas, rows, cols, i, j)};
      if (canvas[i][j])
        updatedCanvas[i][j] = (count == 2 || count == 3);
      else
        updatedCanvas[i][j] = (count == 3);
    }
  }
  canvas = updatedCanvas;
}
