// Postal Bar Code
// Write a program that asks the user for a five-digit zip code and prints
// the corresponding postal bar code.
//
// Rules and Specifications:
// 1) Prompt the user to enter a five-digit zip code.
// 2) Encode each of the five digits using the postal bar code scheme.
// 3) Before the encoded digits, print a full-height frame bar.
// 4) After the five encoded digits, compute and encode a check digit.
// 5) The check digit is chosen so that the sum of all five zip-code digits
//    plus the check digit is a multiple of 10.
// 6) After the check digit, print a final full-height frame bar.
// 7) Use ':' to represent a half bar.
// 8) Use '|' to represent a full bar.
//
// Encoding Information:
// 1) Each digit is encoded using five bars.
// 2) The bar positions have weights 7, 4, 2, 1, 0.
// 3) A 0 in the table means a half bar, and a 1 means a full bar.
// 4) The digit encodings are:
//
//    1 = 00011
//    2 = 00101
//    3 = 00110
//    4 = 01001
//    5 = 01010
//    6 = 01100
//    7 = 10001
//    8 = 10010
//    9 = 10100
//    0 = 11000
//
// Example:
// If the zip code is 95014, the sum of the digits is 19, so the check digit
// is 1 to make the total 20.
//
// Example Output:
// |:|::|:::||::|:|::|::|:|:|::|||

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

void ignoreLine();
bool recoverStream();
std::string getString(const std::string& prompt);
bool isFiveDigitZipcode(const std::string& s);
int getCheckDigit(const std::string& zipcode);
std::string digitEncoding(int digit);
std::string getScheme(const std::string& code);

int main()
{
    std::string zipcode{getString("Enter a 5 digit zipcode: ")};
    int checkDigit{getCheckDigit(zipcode)};
    std::string scheme{getScheme(zipcode + std::to_string(checkDigit))};

    std::cout << scheme << '\n';

    return 0;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool recoverStream()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            exit(1);
        }

        std::cin.clear();
        ignoreLine();
        return true;
    }

    return false;
}

bool isFiveDigitZipcode(const std::string& s)
{
    if (s.length() != 5)
    {
        return false;
    }

    for (unsigned int i{0}; i < s.length(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
    }

    return true;
}

std::string getString(const std::string& prompt)
{
    while (true)
    {
        std::string s{};
        std::cout << prompt;
        std::cin >> s;

        if (recoverStream() || !isFiveDigitZipcode(s))
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        return s;
    }
}

int getCheckDigit(const std::string& zipcode)
{
    int sum{};

    for (unsigned int i{0}; i < zipcode.length(); ++i)
    {
        sum += zipcode[i] - '0';
    }

    if (sum % 10 == 0)
    {
        return 0;
    }

    return 10 - (sum % 10);
}

std::string digitEncoding(int digit)
{
    switch (digit)
    {
    case 0:
        return "||:::";
    case 1:
        return ":::||";
    case 2:
        return "::|:|";
    case 3:
        return "::||:";
    case 4:
        return ":|::|";
    case 5:
        return ":|:|:";
    case 6:
        return ":||::";
    case 7:
        return "|:::|";
    case 8:
        return "|::|:";
    case 9:
        return "|:|::";
    default:
        return "";
    }
}

std::string getScheme(const std::string& code)
{
    std::string s{"|"};

    for (unsigned int i{0}; i < code.length(); ++i)
    {
        s += digitEncoding(code[i] - '0');
    }

    s += "|";
    return s;
}
