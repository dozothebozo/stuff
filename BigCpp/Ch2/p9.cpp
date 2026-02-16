// Implement a program that directs a cashier how to give change.
// The program has two inputs:
// the amount due and the amount received from the customer.
// It should compute the difference, and compute the
// dollars, quarters, dimes, nickels, and pennies that the customer should
// receive in return. Hint: First transform the difference into an integer
// balance, denominated in pennies. Then compute the whole dollar amount.
// Subtract it from the balance. Compute the number of quarters needed. Repeat
// for dimes and nickels. Display the remaining pennies.
//
// example:
// Enter the amount due: 3.33
// Enter the amount received: 5.00
// Your Change is :
// Dollars     Quarters     Dimes     Nickels     Pennies
// 1           2            1         1           2

#include <iostream>

namespace Coins {
  constexpr int dollars{100};
  constexpr int quarters{25};
  constexpr int dimes{10};
  constexpr int nickels{5};
  constexpr int pennies{1};
} // namespace Coins

double getAmountDue() {
  double amountDue{};
  std::cout << "Enter the amount due: ";
  std::cin >> amountDue;
  return amountDue;
}

double getAmountReceived() {
  double amountReceived{};
  std::cout << "Enter the amount received: ";
  std::cin >> amountReceived;
  return amountReceived;
}

int calculateChange(double amountDue, double amountReceived) {
  return static_cast<int>((amountReceived - amountDue) * Coins::dollars);
};

int main() {
  double amountDue{getAmountDue()};
  double amountReceived{getAmountReceived()};
  int change{calculateChange(amountDue, amountReceived)};

  int dollars{change / Coins::dollars};
  int quarters{change % (dollars * Coins::dollars) / Coins::quarters};
  int dimes{change % (dollars * Coins::dollars + quarters * Coins::quarters) / Coins::dimes};
  int nickels{change % (dollars * Coins::dollars + quarters * Coins::quarters + dimes * Coins::dimes) / Coins::nickels};
  int pennies{change % (dollars * Coins::dollars + quarters * Coins::quarters + dimes * Coins::dimes + nickels * Coins::nickels) / Coins::pennies};

  std::cout << "Change (in pennies): " << change << '\n';
  std::cout << "Dollars: " << dollars << '\n';
  std::cout << "Quarters: " << quarters << '\n';
  std::cout << "Dimes: " << dimes << '\n';
  std::cout << "Nickels: " << nickels << '\n';
  std::cout << "Pennies: " << pennies << '\n';

  return 0;
}
