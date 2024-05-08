#include <iostream>

int *ptrMin(int array[], int size) {
  int indexMin{0};
  for (int i{1}; i < size; ++i) {
    if (array[i] < array[indexMin])
      indexMin = i;
  }
  return &array[indexMin];
}

int *ptrMax(int array[], int size) {
  int indexMax{0};
  for (int i{1}; i < size; ++i) {
    if (array[i] > array[indexMax])
      indexMax = i;
  }
  return &array[indexMax];
}

int main() {
  constexpr int size{6};
  int array[size];

  for (int i{0}; i < size; ++i) {
    std::cin >> array[i];
  }

  int *max = ptrMax(array, size);
  int *min = ptrMin(array, size);

  int temp = *max;
  *max = *min;
  *min = temp;

  for (int i{0}; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << '\n';

  return 0;
}
