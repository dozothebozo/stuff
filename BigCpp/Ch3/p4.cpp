// Write a program that translates a letter grade into a number grade.
//
// Rules for Letter Grades:
// 1) Base numeric values are:
//    A = 4.0
//    B = 3.0
//    C = 2.0
//    D = 1.0
//    F = 0.0
// 2) Modifier rules:
//    '+' increases the numeric value by 0.3
//    '-' decreases the numeric value by 0.3
// 3) Exceptions:
//    - An 'A+' has a value of 4.0.
//    - There is no 'F+' or 'F-'.
//
// Example:
//
// Computer: Enter a letter grade:
// User: B-
// Computer: The numeric value is 2.7.

#include <iostream>
#include <string>

std::string getLetterGrade() {
  std::string s{};
  std::cout << "Enter a letter grade: ";
  std::getline(std::cin >> std::ws, s);
  return s;
}

int main() {
  std::string letterGrade{getLetterGrade()};
  double numericValue{};

  switch (letterGrade[0]) {
    case ('A'):
      numericValue = 4.0;
      break;
    case ('B'):
      numericValue = 3.0;
      break;
    case ('C'):
      numericValue = 2.0;
      break;
    case ('D'):
      numericValue = 1.0;
      break;
    case ('F'):
      numericValue = 0.0;
      break;
    default:
      std::cout << "Invalid letter grade.\n";
      return 1;
  }

  if (letterGrade.length() <= 1 || letterGrade[0] == 'F') {
    std::cout << "The numeric value is " << numericValue << ".\n";
    return 0;
  }

  if (letterGrade[1] == '+' && letterGrade[0] != 'A') {
    numericValue += 0.3;
  } else if (letterGrade[1] == '-') {
    numericValue -= 0.3;
  }

  std::cout << "The numeric value is " << numericValue << ".\n";

  return 0;
}
