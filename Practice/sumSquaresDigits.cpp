// Write and test a recursive function named sumSquaresDigits with an int argument that will
// calculate and return the sum of the squares of its digits. If the argument has only one digit,
// the function should return the square of that digit. For example: sumSquaresDigits(203) should
// return 4 + 0 + 9 = 13; sumSquaresDigits(7) should return 49.

#include <cstdlib>
#include <iostream>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
int getInteger(const string& prompt);
int sumSquaresDigits(int num);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        int num{getInteger("Enter an integer: ")};
        cout << sumSquaresDigits(num) << '\n';

        cout << "Would you like to do it again? (y/n): ";
        cin >> choice;

        ignoreLine();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void ignoreLine()
{
    cin.ignore(IGNORE_SIZE, '\n');
}

bool recoverStream()
{
    if (!cin)
    {
        if (cin.eof())
        {
            exit(1);
        }
        cin.clear();
        ignoreLine();
        return true;
    }
    return false;
}

int getInteger(const string& prompt)
{
    while (true)
    {
        int value{};
        cout << prompt;
        cin >> value;

        if (recoverStream() || value < 0)
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        ignoreLine();
        return value;
    }
}

int sumSquaresDigits(int num)
{
    if (num < 10)
        return num * num;

    int lastDigit{num % 10};

    return (lastDigit * lastDigit) + sumSquaresDigits(num / 10);
}
