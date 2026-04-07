// Write a recursive function reversed with a string argument that will calculate and return the
// reversal of its argument by splitting its argument into two parts at position n/2 where n is the
// length of the string argument, calling itself recursively to reverse each part, and combining the
// two reversed parts to produce the reversal of the whole.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
string getString(const string& prompt);
string reverseStr(const string& str);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        string str{getString("Enter a string to reverse: ")};

        cout << reverseStr(str) << '\n';

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

string reverseStr(const string& str)
{
    if (str.length() <= 1)
    {
        return str;
    }

    string left{str.substr(0, str.length() / 2)};
    string right{str.substr(str.length() / 2)};

    return reverseStr(right) + reverseStr(left);
}
