// Write a program that prints all solutions to the quadratic equation: ax^2 + bx + c = 0
// Read in a, b, c and use the quadratic formula. If the discriminant
// is negative, display a message stating that there are no solutions.

#include <cmath>
#include <iostream>

int main() {
  int a{}, b{}, c{};
  std::cout << "Enter terms (a b c): ";
  std::cin >> a >> b >> c;

  double discriminant{std::pow(b, 2) - 4 * a * c};
  std::cout << "discriminant: " << discriminant << '\n';

  if (discriminant < 0) {
    std::cout << "no real solutions\n";
  } else if (discriminant == 0) {
    std::cout << "x = " << (-b / 2 * a) << '\n';
  } else {
    std::cout << "x1 = " << (-b + std::sqrt(discriminant)) / 2 * a << '\n';
    std::cout << "x2 = " << (-b - std::sqrt(discriminant)) / 2 * a << '\n';
  }

  return 0;
}
