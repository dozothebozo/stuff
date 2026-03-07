// Reverse the Digits
// Write a program that reads an integer and prints its digits in reverse order.
//
// Rules and Specifications:
// 1) Do not convert the integer to a string to reverse it.
// 2) You must use mathematical operations. Specifically, use the modulus
//    operator (%) to extract the last digit.
// 3) Use integer division (/) to remove the last digit from the number.
// 4) The loop should continue until the number has been reduced to 0.
// 5) The program should handle positive integers.
//
// Example:
//
// Computer: Enter an integer:
// User: 7349
// Computer: Reversed integer: 9437

#include <cstdlib>
#include <iostream>
#include <limits>

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction() {
  if (!std::cin) {
    if (std::cin.eof()) {
      std::exit(0);
    }
    std::cin.clear();
    ignoreLine();
    return true;
  }
  return false;
}

int getInteger() {
  while (true) {
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Invalid input. Try again.\n";
      continue;
    }

    ignoreLine();

    return x;
  }
}

int main() {
  int num{getInteger()};
  std::cout << num;

  return 0;
}
