#include <iostream>

int main(int argc, char *argv[]) {
  int y, m, d;
  bool t;
  std::cin >> m;
  std::cin >> y;
  if (y % 400 == 0) {
    t = true;
  } else if (y % 100 == 0) {
    t = false;
  } else if (y % 4 == 0) {
    t = true;
  } else {
    t = false;
  }
  if (m > 7 && m % 2 == 0) {
    d = 31;
  } else if (m < 8 && m % 2 == 1) {
    d = 31;
  } else if (m == 2) {
    t ? d = 29 : d = 28;
  } else {
    d = 30;
  }
  std::cout << d << std::endl;
  return 0;
}
