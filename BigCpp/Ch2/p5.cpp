// Write a program that prompts the user for a radius and then prints:
// The area and circumference of a circle with that radius
// The volume and surface area of a sphere with that radius

#include <cmath>
#include <iostream>
#include "constants.h"

double getRadius() {
  double r{};
  std::cout << "Enter the radius of a circle: ";
  std::cin >> r;
  return r;
}

double area(double r) {
  return constants::pi * std::pow(r, 2);
}

double circumference(double r) {
  return 2 * constants::pi * r;
}

double volume(double r) {
  return 4.00 / 3.00 * constants::pi * std::pow(r, 3);
}

double surfaceArea(double r) {
  return 4 * constants::pi * std::pow(r, 2);
}

int main() {
  double radius{getRadius()};

  std::cout << "Radius: " << radius << '\n';
  std::cout << "Area: " << area(radius) << '\n';
  std::cout << "Circumference: " << circumference(radius) << '\n';
  std::cout << "Volume: " << volume(radius) << '\n';
  std::cout << "Surface Area: " << surfaceArea(radius) << '\n';

  return 0;
}
