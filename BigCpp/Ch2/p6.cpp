// Write a program that asks the user for the lengths of the sides of a
// rectangle and then print:
// The area and perimeter of the rectangle
// The length of the diagonal (use the Pythagorean theorem)

#include <cmath>
#include <iostream>

double getLength() {
  double l{};
  std::cout << "Enter the length of the rectangle: ";
  std::cin >> l;
  return l;
}

double getWidth() {
  double w{};
  std::cout << "Enter the width of the rectangle: ";
  std::cin >> w;
  return w;
}

double getArea(double l, double w) { return l * w; }

double getPerimeter(double l, double w) { return 2 * l + 2 * w; }

double getDiagonal(double l, double w) { return std::sqrt(l * l + w * w); }

int main() {
  double length{getLength()};
  double width{getWidth()};
  double area{getArea(length, width)};
  double perimeter{getPerimeter(length, width)};
  double diagonal{getDiagonal(length, width)};

  std::cout << "Length: " << length << '\n';
  std::cout << "Width: " << width << '\n';
  std::cout << "Area: " << area << '\n';
  std::cout << "Perimeter: " << perimeter << '\n';
  std::cout << "Diagonal: " << diagonal << '\n';

  return 0;
}
