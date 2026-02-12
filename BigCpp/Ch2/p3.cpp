// Write a program that prompts the user for two integers and then prints:
// The sum
// The difference
// The product
// The average
// The distance (absolute value of the difference)
// The maximum (the larger of the two)
// The minimum (the smaller of the two)

#include <iostream>

int getInteger() {
  int x{};
  std::cout << "Enter an Integer: ";
  std::cin >> x;
  return x;
}

int sum(int x, int y) { return x + y; }

int difference(int x, int y) { return x - y; }

int product(int x, int y) { return x * y; }

int distance(int x, int y) {
  int res{difference(x, y)};
  if (res < 0) {
    return -res;
  }
  return res;
}

int maximum(int x, int y) { return (x > y ? x : y); }

int minimum(int x, int y) { return (x < y ? x : y); }

int main() {
  int x{getInteger()};
  int y{getInteger()};

  std::cout << "sum: " << sum(x, y) << '\n';
  std::cout << "difference: " << difference(x, y) << '\n';
  std::cout << "product: " << product(x, y) << '\n';
  std::cout << "distance: " << distance(x, y) << '\n';
  std::cout << "maximum: " << maximum(x, y) << '\n';
  std::cout << "minimum: " << minimum(x, y) << '\n';

  return 0;
}
