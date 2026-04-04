// Write and test a recursive function named isPalindrome with a string argument that will determine
// whether its argument reads the same forward and backward. The function should return true if the
// string is a palindrome and false otherwise. For example: isPalindrome("level") should return
// true; isPalindrome("computer") should return false.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
string getString(const string& prompt);
bool isPalindrome(const string& word);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        string word{getString("Enter a word: ")};

        if (isPalindrome(word))
        {
            cout << word << " is a palindrome.\n";
        }
        else
        {
            cout << word << " is not a palindrome.\n";
        }

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

        if (s.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
            continue;
        }

        return s;
    }
}

bool isPalindrome(const string& word)
{
    if (word.length() < 2)
    {
        return true;
    }

    if (word[0] != word[word.length() - 1])
    {
        return false;
    }

    return isPalindrome(word.substr(1, word.length() - 2));
}
