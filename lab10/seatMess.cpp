#include <iostream>
#include <limits>
#include <vector>

std::vector<int> switchIndexesAndValues(const std::vector<int> &vec) {
  std::vector<int> switchedVector = vec;

  for (size_t i = 0; i < switchedVector.size(); ++i) {
    // Swap index and value
    std::swap(switchedVector[i], switchedVector[switchedVector[i]]);
  }

  return switchedVector;
}

int main() {
  std::vector<int> numbers;

  // Input phase for the initial vector
  std::cout << "Enter integers for the initial vector (enter a non-integer to "
               "finish input):"
            << std::endl;
  int input;
  while (std::cin >> input) {
    numbers.push_back(input);
  }

  // Clear the error state and ignore any remaining input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Display the original vector
  std::cout << "Original vector: ";
  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Switch indexes and values and get the new vector
  std::vector<int> switchedNumbers = switchIndexesAndValues(numbers);

  // Display the modified vector
  std::cout << "Modified vector: ";
  for (const auto &num : switchedNumbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
