#include <iostream>

int findMin(const int arr[], int size);
int findMax(const int arr[], int size);
void switchMinAndMax(int arr[], int size);
int countUniqueElements(const int arr[], int size);
int findMinIndex(const int arr[], int size);
int sumBetweenNegatives(const int arr[], int size);
void sortArrayAbs(double arr[], int size);

template <typename T>
void printArray(const T arr[], int size) {
  for (int i{0}; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  constexpr int n{10};
  int arr[n] = {12, 15, 115, 2, -15, -4, 25, 33, 52, 33};
  printArray<int>(arr, n);
  std::cout << "max: " << findMax(arr, n) << '\n';
  std::cout << "max: " << findMin(arr, n) << '\n';
  switchMinAndMax(arr, n);
  std::cout << "switch: ";
  printArray<int>(arr, n);
  std::cout << "Unique: " << countUniqueElements(arr, n) << '\n';
  std::cout << "Min Index: " << findMinIndex(arr, n) << '\n';
  std::cout << "negSum: " << sumBetweenNegatives(arr, n) << '\n';

  double fltArr[7] = {23.2, 3.3, 0.0, 0.2, -5.3, -0.3, 4.0};
  std::cout << "float array: ";
  printArray<double>(fltArr, 7);
  sortArrayAbs(fltArr, 7);
  std::cout << "sorted float array: ";
  printArray<double>(fltArr, 7);

  return 0;
}
int findMin(const int arr[], int size) {
  int min = arr[0];

  for (int i{1}; i < size; ++i) {
    if (arr[i] < min)
      min = arr[i];
  }

  return min;
}

int findMax(const int arr[], int size) {
  int max = arr[0];

  for (int i{1}; i < size; ++i) {
    if (arr[i] > max)
      max = arr[i];
  }

  return max;
}

void switchMinAndMax(int arr[], int size) {
  int minIndex{};
  int maxIndex{};

  for (int i{1}; i < size; ++i) {
    if (arr[i] < arr[minIndex]) {
      minIndex = i;
    } else if (arr[i] > arr[maxIndex]) {
      maxIndex = i;
    }
  }

  int temp = arr[minIndex];
  arr[minIndex] = arr[maxIndex];
  arr[maxIndex] = temp;
}

int countUniqueElements(const int arr[], int size) {
  int uniqueCount{size};

  for (int i{}; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr[i] == arr[j]) {
        --uniqueCount;
        break;
      }
    }
  }

  return uniqueCount;
}

int findMinIndex(const int arr[], int size) {
  int minIndex{0};

  for (int i{1}; i < size; ++i) {
    if (arr[i] < arr[minIndex]) {
      minIndex = i;
    }
  }

  return minIndex;
}

int sumBetweenNegatives(const int arr[], int size) {
  int firstNegativeIndex{-1};
  int sum{0};

  for (int i{0}; i < size; ++i) {
    if (arr[i] < 0) {
      firstNegativeIndex = i;
      break;
    }
  }

  if (firstNegativeIndex == -1 || firstNegativeIndex == size - 1) {
    return 0;
  }

  for (int i = firstNegativeIndex + 1; i < size; ++i) {
    if (arr[i] < 0) {
      for (int j = firstNegativeIndex + 1; j < i; ++j) {
        sum += arr[j];
      }
      break;
    }
  }

  return sum;
}
void sortArrayAbs(double arr[], int size) {
  int moveIndex{};
  while (moveIndex < size && std::abs(arr[moveIndex]) < 1) {
    ++moveIndex;
  }

  if (moveIndex == size) {
    return;
  }

  for (int j = 0; j < size; ++j) {
    if (std::abs(arr[j]) < 1) {
      std::swap(arr[moveIndex], arr[j]);
      ++moveIndex;
      if (moveIndex == size) {
        break;
      }
    }
  }
}
