// Write a program that factors an integer.
//
// Requirements:
// 1) Ask the user to enter a positive integer.
// 2) Print all of its prime factors, one per line.
// 3) If a factor appears more than once, print it multiple times.
//
// Example:
//
// Computer: Enter a positive integer:
// User: 150
// Computer:
// 2
// 3
// 5
// 5
//

#include <iostream>

void printPrimeFactors(int n) {
  for (int factor = 2; factor * factor <= n; ++factor) {
    while (n % factor == 0) {
      std::cout << factor << '\n';
      n /= factor;
    }
  }

  if (n > 1) {
    std::cout << n << '\n';
  }
}

int main() {
  int x{};
  std::cout << "Enter a positive integer: ";
  std::cin >> x;

  printPrimeFactors(x);
}
