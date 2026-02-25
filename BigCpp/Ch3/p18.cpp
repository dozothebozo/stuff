// The Fibonacci numbers are defined by the sequence:
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
//
// Each number is the sum of the two preceding ones. This program computes
// the n-th Fibonacci number using an iterative algorithm:
//
// 1) Initialize fold1 = 1 and fold2 = 1.
// 2) Calculate fnew = fold1 + fold2.
// 3) Update variables: fold2 becomes fold1, and fold1 becomes fnew.
// 4) Repeat the process until the desired n-th position is reached.
//
// Example:
//
// Computer: Enter the index n to compute the n-th Fibonacci number:
// User: 6
// Computer: Fibonacci number #6 is 8

#include <iostream>
#include <limits>

int getIndex() {
  int x{};

  while (true) {
    std::cout << "Enter the index n to compute the n-th Fibonacci number: ";
    if (std::cin >> x) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return x;
    } else {
      std::cout << "Invalid input. Please try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  int n{getIndex()};

  long long newer{1};
  long long older{1};
  long long current{};

  if (n == 1 || n == 2) {
    std::cout << "Fibonacci number #" << n << " is " << 1;
    return 0;
  }

  for (int i{3}; i <= n; ++i) {
    current = newer + older;
    older = newer;
    newer = current;
  }

  std::cout << "Fibonacci number #" << n << " is " << current;

  return 0;
}
