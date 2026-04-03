// Write a function isPalindromeNumber that will determine whether a given positive integer is a
// palindrome. A palindrome reads the same from left to right and from right to left. For example,
// 1331 and 2442 are palindromes.

// Use this function in another function that will find all palindromic integers in an interval from
// the first to the second argument of this function. Print the palindromic integers in a well
// aligned table, five per line.

#include <iomanip>
#include <iostream>

using namespace std;

// function prototypes
int getPlaceValue(int num);
bool isPalindromeNumber(const int num);
void printPalindromeInRange(int min, int max);

// global declarations of constants
const int INTERVAL_MIN = 1;
const int INTERVAL_MAX = 10000000;
const int ALIGN = 5;

int main()
{
    printPalindromeInRange(INTERVAL_MIN, INTERVAL_MAX);
    return 0;
}

int getPlaceValue(int num)
{
    int placeValue = 1;

    while (num >= 10)
    {
        num /= 10;
        placeValue *= 10;
    }

    return placeValue;
}

bool isPalindromeNumber(const int num)
{
    if (num < 0)
    {
        return false;
    }

    if (num < 10)
    {
        return true;
    }

    if (num % 10 == 0)
    {
        return false;
    }

    int temp = num;
    int placeValue = getPlaceValue(num);
    int reverse = 0;

    while (temp > 0)
    {
        int lastDigit = temp % 10;
        reverse += lastDigit * placeValue;
        placeValue /= 10;
        temp /= 10;
    }

    return num == reverse;
}

void printPalindromeInRange(int min, int max)
{
    int count = 0;

    for (int i = min; i <= max; ++i)
    {
        if (isPalindromeNumber(i))
        {
            cout << setw(8) << i;
            ++count;

            if (count % ALIGN == 0)
            {
                cout << '\n';
            }
        }
    }

    if (count % ALIGN != 0)
    {
        cout << '\n';
    }
}
