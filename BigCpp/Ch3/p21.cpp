// Write a program that prompts the user for an integer n
// and then prints out all prime numbers up to n (inclusive).
//
// Definition:
// A number is prime if it is greater than 1 and is not divisible by any number
// except 1 and itself.
//
// Program behavior:
// 1) Ask the user for an integer n.
// 2) For each integer k from 2 to n, determine if k is prime.
// 3) Print each prime number on its own line.
//
// Example I O:
//
// Computer: Enter an integer:
// User: 20
// Computer:
// 2
// 3
// 5
// 7
// 11
// 13
// 17
// 19
//

#include <cmath>
#include <iostream>

int getInteger() {
  int n{};
  std::cout << "Enter an integer: ";
  std::cin >> n;
  return n;
}

bool isPrime(int n) {
  if (n <= 1)
    return false;

  if (n == 2)
    return true;

  if (n % 2 == 0)
    return false;

  for (int i{3}; i <= std::sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n{getInteger()};

  for (int i{2}; i <= n; ++i) {
    if (isPrime(i)) {
      std::cout << i << '\n';
    }
  }

  return 0;
}
