// Project:
// Author:
// Date:

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
int getInteger(const string& prompt);
double getDouble(const string& prompt);
string getString(const string& prompt);
int getIntegerInRange(int min, int max, const string& prompt = "");
bool getBoolean(const string& prompt);

// templates
template <typename T> T getNumber(const string& prompt)
{
    while (true)
    {
        T value{};

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

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
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

double getDouble(const string& prompt)
{
    while (true)
    {
        double value{};

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

string getString(const string& prompt)
{
    while (true)
    {
        string s{};

        cout << prompt;
        getline(cin, s);

        if (recoverStream())
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (s.length() == 0)
        {
            cout << "Input cannot be empty. Please try again.\n";
            continue;
        }

        return s;
    }
}

int getIntegerInRange(int min, int max, const string& prompt)
{
    while (true)
    {
        int x{};

        if (!prompt.empty())
        {
            cout << prompt;
        }
        else
        {
            cout << "Enter a number between " << min << " and " << max << ": ";
        }

        cin >> x;

        if (recoverStream())
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (x < min || x > max)
        {
            cout << "Input must be between " << min << " and " << max << ". Please try again.\n";
            ignoreLine();
            continue;
        }

        ignoreLine();
        return x;
    }
}

bool getBoolean(const string& prompt)
{
    while (true)
    {
        char value{};

        cout << prompt;
        cin >> value;

        if (recoverStream())
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        ignoreLine();

        if (value == 'y' || value == 'Y')
        {
            return true;
        }

        if (value == 'n' || value == 'N')
        {
            return false;
        }

        cout << "Invalid input. Please enter y or n.\n";
    }
}
