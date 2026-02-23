// Write a program that converts a positive integer into the Roman number system.
// Roman numerals use the digits:
//
// I    1
// V    5
// X    10
// L    50
// C    100
// D    500
// M    1000
//
// Numbers are formed according to these rules:
// 1) Only numbers up to 3,999 are represented.
// 2) As in the decimal system, the thousands, hundreds, tens, and ones are expressed separately.
// 3) The numbers 1 to 9 are expressed as:
//      I     1
//      II    2
//      III   3
//      IV    4
//      V     5
//      VI    6
//      VII   7
//      VIII  8
//      IX    9
//
// Same pattern as 1-9, but with different symbols:
// - Ones:      I, V, X
// - Tens:      X, L, C
// - Hundreds:  C, D, M
// - Thousands: M (up to MMM for 3000)
//
// Example:
//
// Computer: Please enter a positive integer (1..3999):
// User: 1978
// Computer: The Roman numeral is MCMLXXVIII

#include <iostream>
#include <string>

int getInteger() {
  int x{};
  while (!(x >= 1 && x <= 3999)) {
    std::cout << "Please enter a positive integer (1, 3999): ";
    std::cin >> x;
  }
  return x;
}

// - Thousands: M (up to MMM for 3000)
std::string getThousands(int th) {
  switch (th) {
    case 1:
      return "M";
    case 2:
      return "MM";
    case 3:
      return "MMM";
    default:
      return "";
  }
}

// - Hundreds: C, D, M
std::string getHundreds(int h) {
  switch (h) {
    case 1:
      return "C";
    case 2:
      return "CC";
    case 3:
      return "CCC";
    case 4:
      return "CD";
    case 5:
      return "D";
    case 6:
      return "DC";
    case 7:
      return "DCC";
    case 8:
      return "DCCC";
    case 9:
      return "CM";
    default:
      return "";
  }
}

// - Tens: X, L, C
std::string getTens(int t) {
  switch (t) {
    case 1:
      return "X";
    case 2:
      return "XX";
    case 3:
      return "XXX";
    case 4:
      return "XL";
    case 5:
      return "L";
    case 6:
      return "LX";
    case 7:
      return "LXX";
    case 8:
      return "LXXX";
    case 9:
      return "XC";
    default:
      return "";
  }
}

// - Ones: I, V, X
std::string getOnes(int o) {
  switch (o) {
    case 1:
      return "I";
    case 2:
      return "II";
    case 3:
      return "III";
    case 4:
      return "IV";
    case 5:
      return "V";
    case 6:
      return "VI";
    case 7:
      return "VII";
    case 8:
      return "VIII";
    case 9:
      return "IX";
    default:
      return "";
  }
}

int main() {
  int num{getInteger()};

  int thousands{num / 1000};
  int hundreds{(num % 1000) / 100};
  int tens{(num % 100) / 10};
  int ones{num % 10};

  // std::cout << "Thousands: " << thousands << '\n';
  // std::cout << "Hundreds: " << hundreds << '\n';
  // std::cout << "Tens: " << tens << '\n';
  // std::cout << "ones: " << ones << '\n';

  std::cout << "The Roman numeral is ";
  std::cout << getThousands(thousands) << getHundreds(hundreds) << getTens(tens) << getOnes(ones) << '\n';

  return 0;
}
