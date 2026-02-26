#include <iostream>
#include <string>
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

std::string getString() {
  std::string s{};
  std::cout << "Enter text: ";
  std::getline(std::cin >> std::ws, s);
  return s;
}

bool isEven(int n) {
  return (n % 2 == 0);
}

bool isOdd(int n) {
  return (n % 2 != 0);
}

bool isPositive(int n) {
  return (n > 0);
}

bool isNegative(int n) {
  return (n < 0);
}

int getIntegerInRange(int min, int max) {
  int x{};
  while (true) {
    std::cout << "Enter a number between " << min << " and " << max << ": ";
    if (std::cin >> x && x >= min && x <= max) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return x;
    } else {
      std::cout << "Invalid input. ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  char choice{};

  do {
    std::cout << "I am running\n";

    std::cout << "Do you want to continue? (y/n): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  } while (choice != 'n' && choice != 'N');

  std::cout << "Stopped.\n";

  return 0;
}
