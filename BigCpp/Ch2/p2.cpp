// Write a program that displays the squares, cubes, and fourth powers
// of the numbers 1 through 5.

#include <cmath>
#include <iostream>

void printPower(int x) {
  std::cout << x << " squared: " << std::pow(x, 2) << '\n';
  std::cout << x << " cubed: " << std::pow(x, 3) << '\n';
  std::cout << x << " to the fourth power: " << std::pow(x, 4) << '\n';
}

int main() {
  printPower(1);
  std::cout << "--------------\n";
  printPower(2);
  std::cout << "--------------\n";
  printPower(3);
  std::cout << "--------------\n";
  printPower(4);
  std::cout << "--------------\n";
  printPower(5);
  return 0;
}
