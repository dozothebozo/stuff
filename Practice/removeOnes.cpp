// Write a recursive function named removeOnes with an int argument that will calculate and return
// its argument with all ones removed. If all digits of the argument are ones, the function should
// return 0. For example: removeOnes(1214) should return 24; removeOnes(1111) should return 0.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
int getInteger(const string& prompt);
int removeOnes(int num, int placeValue = 1);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        int num{getInteger("Enter an integer: ")};

        cout << num << ": " << removeOnes(num) << '\n';

        cout << "Would you like to do it again? (y/n): ";
        cin >> choice;

        if (recoverStream())
        {
            break;
        }

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

        if (recoverStream())
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        ignoreLine();
        return value;
    }
}

int removeOnes(int num, int placeValue)
{
    if (num < 0)
    {
        return -removeOnes(-num, placeValue);
    }

    if (num < 10)
    {
        if (num == 1)
        {
            return 0;
        }
        return num * placeValue;
    }

    int lastDigit = num % 10;
    num /= 10;

    return ((lastDigit == 1) ? 0 + removeOnes(num, placeValue)
                             : lastDigit * placeValue + removeOnes(num, placeValue * 10));
}
