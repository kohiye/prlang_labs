#include <cmath>
#include <iostream>

int inputPosition(char coord, int pos_num);
void validOr(bool valid_move);

int main() {
  int pos1_x = inputPosition('x', 1);
  int pos1_y = inputPosition('y', 1);

  int pos2_x = inputPosition('x', 2);
  int pos2_y = inputPosition('y', 2);

  bool valid_move{false};

  if (pos1_x == pos2_x || pos1_y == pos2_y) {
    valid_move = true;
  } else if (std::abs(pos1_x - pos2_x) == std::abs(pos1_y - pos2_y)) {
    valid_move = true;
  }

  validOr(valid_move);

  return 0;
}

int inputPosition(char coord, int pos_num) {
  std::cout << "Input the " << coord << " of position " << pos_num << " : ";
  int pos{};
  std::cin >> pos;
  return pos;
}

void validOr(bool valid_move) {
  if (valid_move) {
    std::cout << "Your move is VALID\n";
  } else {
    std::cout << "Your move is NOT VALID\n";
  }
}
