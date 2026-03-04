#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// learncpp
// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  // Check for failed extraction
  if (!std::cin) // If the previous extraction failed
  {
    if (std::cin.eof()) // If the stream was closed
    {
      std::exit(0); // Shut down the program now
    }

    // Let's handle the failure
    std::cin.clear(); // Put us back in 'normal' operation mode
    ignoreLine();     // And remove the bad input

    return true;
  }

  return false;
}

int getInteger() {
  while (true) {
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Invalid input. Please try again.\n";
      continue;
    }

    ignoreLine();
    return x;
  }
}

double getDouble() {
  while (true) {
    double x{};
    std::cout << "Enter a decimal number: ";
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Invalid input. Please try again.\n";
      continue;
    }

    ignoreLine();
    return x;
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
  while (true) {
    int x{};
    std::cout << "Enter a number between " << min << " and " << max << ": ";
    std::cin >> x;

    if (clearFailedExtraction() || x < min || x > max) {
      std::cout << "Invalid input. Please try again.\n";
      continue;
    }

    ignoreLine();
    return x;
  }
}

int main() {
  std::cout << "Hello World\n";
  return 0;
}
