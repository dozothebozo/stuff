// A year with 366 days is called a leap year.
//
// Rules:
// A year is a leap year if it is divisible by 4.
// BUT it is NOT a leap year if it is divisible by 100.
// HOWEVER, it IS a leap year if it is divisible by 400.
// Before October 15, 1582 (Gregorian calendar),
// there were no exceptions, so any year divisible by 4 was a leap year.
//
// Write a program that:
// Asks the user for a year.
// Determines whether it is a leap year.
// Uses a single if statement.
//
// Example:
//
// Computer: Enter a year:
// User: 2000
// Computer: 2000 is a leap year.
//
// Computer: Enter a year:
// User: 1900
// Computer: 1900 is not a leap year.

#include <iostream>
#include <limits>

int getYear() {
  int x{};

  while (true) {
    std::cout << "Enter a year: ";
    if (std::cin >> x) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return x;
    } else {
      std::cout << "Invalid input. Please try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  char choice{};

  do {
    int year{getYear()};

    if ((year < 1582 && year % 4 == 0) || (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
      std::cout << year << " is a leap year.\n";
    } else {
      std::cout << year << " is not a leap year.\n";
    }

    std::cout << "Do you want to continue? (y/n): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (choice != 'n' && choice != 'N');

  return 0;
}
