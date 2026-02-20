// Write a program that takes user input describing a playing card in the
// following shorthand notation:
//
// A        Ace
// 2...10   Card values
// J        Jack
// Q        Queen
// K        King
// D        Diamonds
// H        Hearts
// S        Spades
// C        Clubs
//
// For Example:
//
// Computer: Enter the card notation
// User: QS
// Computer: Queen of spades

#include <iostream>
#include <string>

std::string getNotation() {
  std::string card{};
  std::cout << "Enter the card notation: ";
  std::cin >> card;
  return card;
}

std::string getSuit(char n) {
  switch (n) {
    case 'D':
      return "Diamonds";
    case 'H':
      return "Hearts";
    case 'S':
      return "Spades";
    case 'C':
      return "Clubs";
    default:
      return "N/A";
  }
}

std::string getRank(char n) {
  switch (n) {
    case 'A':
      return "Ace";
    case 'J':
      return "Jack";
    case 'Q':
      return "Queen";
    case 'K':
      return "King";
    case '2':
      return "Two";
    case '3':
      return "Three";
    case '4':
      return "Four";
    case '5':
      return "Five";
    case '6':
      return "Six";
    case '7':
      return "Seven";
    case '8':
      return "Eight";
    case '9':
      return "Nine";
    case '1':
      return "Ten";
    default:
      return "N/A";
  }
}

int main() {
  std::string cardNotation{getNotation()};
  std::string rank{getRank(cardNotation[0])};
  std::string suit{(rank == "Ten" ? getSuit(cardNotation[2]) : getSuit(cardNotation[1]))};

  std::cout << rank << " of " << suit;

  return 0;
}
