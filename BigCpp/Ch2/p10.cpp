// Write a program that asks the user to input
// The number of gallons of gas in the tank
// The fuel efficiency in miles per gallon
// The price of gas per gallon
// Then print out how far the car can go with the gas in the tank and print the
// cost per 100 miles.

#include <iostream>

double getGallons() {
  double gallons{};
  std::cout << "Enter the number of gallons of gas in the tank: ";
  std::cin >> gallons;
  return gallons;
}

double getFuelEfficiency() {
  double efficiency{};
  std::cout << "Enter the fuel efficiency in miles per gallon: ";
  std::cin >> efficiency;
  return efficiency;
}

double getPrice() {
  double price{};
  std::cout << "Enter the price of gas per gallon: ";
  std::cin >> price;
  return price;
}

int main() {
  double gallons{getGallons()};
  double fuelEfficiency{getFuelEfficiency()};
  double pricePerGallon{getPrice()};
  double miles{gallons * fuelEfficiency};

  std::cout << "With " << gallons << " gallons in the tank, you can go " << miles << " miles." << '\n';
  std::cout << "The cost per 100 miles is: " << (100 / fuelEfficiency * pricePerGallon) << '\n';

  return 0;
}
