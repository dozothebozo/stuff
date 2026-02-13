// Write a program that prompts the user for a measurement in meters and then
// converts it to miles, feet, and inches.

#include <iostream>

double getMeasurement() {
  double x;
  std::cout << "Enter a measurement (in meters): ";
  std::cin >> x;
  return x;
}

double miles(double measurement);
double feet(double measurement);
double inches(double measurement);

int main() {
  double measurement{getMeasurement()};
  std::cout << measurement;
  return 0;
}
