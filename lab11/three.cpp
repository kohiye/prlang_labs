#include <iostream>

double inputNumber(int index) {
  std::cout << "Value " << index << ": ";
  double number{};
  std::cin >> number;
  return number;
}

double &maxThree(double &a, double &b, double &c) {
  if (a >= b && a >= c)
    return a;
  else if (b >= a && b >= c)
    return b;
  else
    return c;
}

int main() {
  double num1{inputNumber(1)};
  double num2{inputNumber(2)};
  double num3{inputNumber(3)};

  double &max = maxThree(num1, num2, num3);
  std::cout << max << '\n';

  max = (num1 + num2 + num3) / 3;
  std::cout << max << '\n';
}
