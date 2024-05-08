#include <cctype>
#include <cstring>
#include <iostream>

size_t stringLength(const char* str) {
  size_t length{0};
  while (str[length] != '\0') {
    ++length;
  }

  return length;
}
// Function to check if a word is a palindrome
bool isPalindromeWord(const char* word, int length) {
  for (int i = 0; i < length / 2; ++i) {
    char char1 = std::tolower(word[i]);
    char char2 = std::tolower(word[length - i - 1]);

    // Check if characters are alphabetic
    if (!std::isalpha(char1)) {
      ++i;
    }
    if (!std::isalpha(char2)) {
      --length;
    }

    if (char1 != char2) {
      return false;
    }
  }

  return true;
}

void countAndPrintPalindromes(const char* input) {
  const char delimiters[] = " \t\n.,;!?";  // Define word delimiters
  char* copy = strdup(input);              // Duplicate the string to modify it
  char* word = strtok(copy, delimiters);

  int count = 0;

  while (word != nullptr) {
    int length = strlen(word);

    if (isPalindromeWord(word, length)) {
      std::cout << "Palindrome word: " << word << std::endl;
      ++count;
    }

    word = strtok(nullptr, delimiters);
  }

  free(copy);  // Free the duplicated string

  std::cout << "Total palindrome words: " << count << std::endl;
}

char* encodeString(const char* str, int shift) {
  int len = strlen(str);
  char* resultStr = new char[len + 1];
  for (int i{0}; i < len; ++i) {
    if (std::isalpha(str[i])) {
      char caseShift = (std::isupper(str[i])) ? 'A' : 'a';
      resultStr[i] = ((str[i] - caseShift - shift) % 26 + 26) % 26 + caseShift;
    } else {
      resultStr[i] = str[i];
    }
  }
  resultStr[len] = '\0';
  return resultStr;
}

double strToDouble(const char* str) {
  double result{0.0};
  int sign{1};
  int index{};
  if (str[0] == '-') {
    sign = -1;
    ++index;
  } else if (str[0] == '+') {
    ++index;
  }
  while (str[index] >= '0' && str[index] <= '9') {
    result = result * 10 + (str[index] - '0');
    ++index;
  }
  if (str[index] == '.') {
    double fraction = 0.1;
    ++index;

    while (str[index] >= '0' && str[index] <= '9') {
      result += (str[index] - '0') * fraction;
      fraction *= 0.1;
      ++index;
    }
  }
  return result;
}

int main() {
  const char* myString = "Cipher, decipher; string.";

  size_t length = stringLength(myString);
  constexpr int shift = 5;
  char* encodedString = encodeString(myString, shift);

  std::cout << "Length of the string: " << length << std::endl;
  std::cout << encodedString << '\n';
  char* decodedString = encodeString(encodedString, -shift);
  std::cout << decodedString << '\n';
  std::cout << strToDouble("336.34") << '\n';
  delete[] encodedString;
  delete[] decodedString;

  return 0;
}
