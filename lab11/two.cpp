#include <iostream>

double calcArea(double *side, double *height) {
  return 0.5 * (*side) * (*height);
}

int main() {
  std::cout << "Enter the side length: ";
  double side{};
  std::cin >> side;
  std::cout << "Enter the height: ";
  double height{};
  std::cin >> height;

  double *sidePtr = &side;
  double *heightPtr = &height;

  std::cout << "Area: " << calcArea(sidePtr, heightPtr) << std::endl;
}
