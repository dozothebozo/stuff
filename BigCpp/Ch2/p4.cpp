// Write a program that prompts the user for a measurement in meters and then
// converts it to miles, feet, and inches.

#include <iostream>

double getMeasurement() {
  double x;
  std::cout << "Enter a measurement (in meters): ";
  std::cin >> x;
  return x;
}

double miles(double measurement) { return measurement / 1609; }

double feet(double measurement) { return measurement * 3.281; }

double inches(double measurement) { return measurement * 39.37; }

int main() {
  double measurement{getMeasurement()};

  std::cout << "Miles: " << miles(measurement) << '\n';
  std::cout << "Feet: " << feet(measurement) << '\n';
  std::cout << "Inches: " << inches(measurement) << '\n';

  return 0;
}
