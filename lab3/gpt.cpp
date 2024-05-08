#include <algorithm> // Include the algorithm library for sorting
#include <iostream>

int main() {
  std::cout
      << "Please enter three integers representing the sides of a triangle:"
      << std::endl;

  int sides[3];
  for (int i = 0; i < 3; ++i) {
    std::cin >> sides[i];
  }

  std::sort(sides, sides + 3); // Sort the sides in ascending order

  if (sides[0] + sides[1] <= sides[2]) {
    std::cout << "UNDEFINED" << std::endl;
  } else if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
    std::cout << "YES, these sides form a right triangle." << std::endl;
  } else {
    std::cout << "NO, these sides do not form a right triangle." << std::endl;
  }

  return 0;
}
