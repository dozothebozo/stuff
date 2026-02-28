// The Times Table
// Write a program that generates a formatted 5x5 multiplication table.
//
// Rules and Specifications:
// 1) The table must include a top header row with column numbers (1 to 5).
// 2) The table must include a left header column with row numbers (1 to 5).
// 3) The interior of the table must contain the products of the corresponding
//    row and column.
// 4) Use nested loops. The outer loop should handle the rows, and the inner
//    loop should handle the columns.
// 5) Ensure the numbers align properly in neat columns. You might need to
//    use formatted output (like setw in C++) to handle single and double
//    digit numbers gracefully.
//
// Example:
//
// Times Table:
//      1  2  3  4  5
//   1  1  2  3  4  5
//   2  2  4  6  8 10
//   3  3  6  9 12 15
//   4  4  8 12 16 20
//   5  5 10 15 20 25

#include <iomanip>
#include <iostream>
#include <limits>

int getInteger() {
  int x{};

  while (true) {
    std::cout << "Enter an integer: ";
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
  int square{getInteger()};

  std::cout << std::setw(1) << " ";
  for (int i{1}; i <= square; ++i) {
    std::cout << std::setw(3) << i;
  }
  std::cout << '\n';

  for (int i{1}; i <= square; ++i) {
    std::cout << i;
    for (int j{1}; j <= square; ++j) {
      std::cout << std::setw(3) << j * i;
    }
    std::cout << '\n';
  }

  return 0;
}
