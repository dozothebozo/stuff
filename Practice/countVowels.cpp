// Write and test a recursive function named countVowels with a string argument that will calculate
// and return the number of vowels in its argument. Treat a, e, i, o, u in both upper and lower case
// as vowels. If the string contains no vowels, the function should return 0. For example:
// countVowels("Computer") should return 3; countVowels("rhythms") should return 0. Submit both the
// function and your main program.

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
string getString(const string& prompt);
bool isVowel(char ch);
int countVowels(const string& str);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        string word{getString("Enter a word: ")};

        cout << word << " has " << countVowels(word) << " vowels.\n";

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

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int countVowels(const string& str)
{
    int strLength = static_cast<int>(str.length());

    if (strLength == 0)
    {
        return 0;
    }

    char lastChar = static_cast<char>(tolower(str[strLength - 1]));

    return (isVowel(lastChar) ? 1 : 0) + countVowels(str.substr(0, strLength - 1));
}
