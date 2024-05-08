#include <iostream>

void circleArea() {
  std::cout << "Enter a radius: ";
  int radius{};
  std::cin >> radius;
  std::cout << "Area of this circle: " << 3.14 * radius * radius << '\n';
}
void rectArea() {
  std::cout << "Enter side one: ";
  int A_side{};
  std::cin >> A_side;
  std::cout << "Enter side two: ";
  int B_side{};
  std::cin >> B_side;
  std::cout << "Area of this rectangle: " << A_side * B_side << '\n';
}
void trigArea() {
  std::cout << "Enter the base: ";
  int base{};
  std::cin >> base;
  std::cout << "Enter the hight: ";
  int hight{};
  std::cin >> hight;
  std::cout << "Area of this rectangle: " << base * hight / 2.0 << '\n';
}

int main() {
  while (true) {
    std::cout << "Select a figure or "
                 "exit:\n(1)Circle\n(2)Rectangle\n(3)Triangle\n(0)Exit"
              << std::endl;
    int selection{};
    std::cin >> selection;
    switch (selection) {
    case 0:
      return 0;
      break;
    case 1:
      circleArea();
      break;
    case 2:
      rectArea();
      break;
    case 3:
      trigArea();
      break;
    }
  }
}
