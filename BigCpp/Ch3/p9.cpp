// Write a program that reads in the name and salary of an employee,
// asks how many hours they worked in the past week, and computes their pay.
//
// Rules and Specifications:
// 1) The salary denotes an hourly wage.
// 2) The program must be able to accept fractional hours worked (e.g., 42.5).
// 3) Regular hourly wage applies to hours worked up to and including 40 hours.
// 4) Any overtime work (hours strictly greater than 40) is paid at 150 percent
//    of the regular wage.
// 5) The program must print a paycheck summary for the employee.
//
// Example:
//
// Computer: Enter employee name:
// User: Jane Smith
// Computer: Enter hourly wage:
// User: 10.00
// Computer: Enter hours worked in the past week:
// User: 45.5
// Computer: Paycheck for Jane Smith: $482.50

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

std::string getEmployeeName() {
  std::string s{};
  std::cout << "Enter employee name: ";
  std::getline(std::cin >> std::ws, s);
  return s;
}

double getDouble(std::string prompt) {
  double x{};

  while (true) {
    std::cout << prompt;
    if (std::cin >> x && x > 0) {
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
  std::string employeeName{getEmployeeName()};
  double wage{getDouble("Enter hourly wage: ")};
  double hours{getDouble("Enter hours worked in the past week: ")};
  double pay{};

  if (hours <= 40) {
    pay = wage * hours;
  } else {
    pay = wage * 40 + (wage * 1.5 * (hours - 40));
  }

  std::cout << std::fixed << std::showpoint << std::setprecision(2);
  std::cout << "Paycheck for " << employeeName << ": $" << pay << '\n';

  return 0;
}
