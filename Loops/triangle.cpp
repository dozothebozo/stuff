// ASCII Art Triangles
// Write a program that uses nested loops to print four different right
// triangle patterns using the asterisk (*) character.
//
// Rules and Specifications:
// 1) Ask the user for the size of the triangle (number of rows).
// 2) Use nested loops to draw the following four shapes sequentially.
// 3) Shape 1: Left-aligned standard triangle (stars increase from 1 to N).
// 4) Shape 2: Left-aligned inverted triangle (stars decrease from N to 1).
// 5) Shape 3: Right-aligned standard triangle (requires a loop for spaces
//    before the stars).
// 6) Shape 4: Right-aligned inverted triangle.
//
// Example (Size 4):
//
// Shape 1:
// *
// **
// ***
// ****
//
// Shape 2:
// ****
// ***
// **
// *
//
// Shape 3:
//    *
//   **
//  ***
// ****
//
// Shape 4:
// ****
//  ***
//   **
//    *

#include <iostream>
#include <limits>

// forward declarations
int getRows();
void printLeftAlignedTriangle(int rows);
void printLeftAlignedInvertedTriangle(int rows);
void printRightAlignedTriangle(int rows);
void printRightAlignedInvertedTriangle(int rows);

int getRows() {
  int x{};

  while (true) {
    std::cout << "Enter the size of the triangle (number of rows): ";
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

// Left-aligned standard triangle (stars increase from 1 to N).
// *
// **
// ***
// ****
void printLeftAlignedTriangle(int rows) {
  for (int i{0}; i < rows; ++i) {
    for (int j{0}; j < i + 1; ++j) {
      std::cout << "*";
    }
    std::cout << '\n';
  }
}

// Left-aligned inverted triangle (stars decrease from N to 1).
// ****
// ***
// **
// *
void printLeftAlignedInvertedTriangle(int rows) {
  for (int i{0}; i < rows; ++i) {
    for (int j{rows - i}; j >= 1; --j) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

// Right-aligned standard triangle (requires a loop for spaces before the stars).
//    *
//   **
//  ***
// ****
void printRightAlignedTriangle(int rows) {
  for (int i{1}; i <= rows; ++i) {
    // Print exactly (totalRows - i) spaces
    for (int j{1}; j <= rows - i; ++j) {
      std::cout << ' ';
    }

    // Print exactly 'i' stars
    for (int k{1}; k <= i; ++k) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

// Right-aligned inverted triangle.
// ****
//  ***
//   **
//    *
void printRightAlignedInvertedTriangle(int rows) {
  for (int i{rows}; i >= 1; --i) {
    for (int j{1}; j <= rows - i; ++j) {
      std::cout << ' ';
    }
    for (int k{1}; k <= i; k++) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

int main() {
  int rows{getRows()};

  std::cout << "Left-aligned Triangle: \n\n";
  printLeftAlignedTriangle(rows);

  std::cout << "\nLeft-aligned Inverted Triangle: \n\n";
  printLeftAlignedInvertedTriangle(rows);

  std::cout << "\nRight-aligned Triangle: \n\n";
  printRightAlignedTriangle(rows);

  std::cout << "\nRight-aligned Inverted Triangle: \n\n";
  printRightAlignedInvertedTriangle(rows);

  return 0;
}
