// Write a function isPerfect that will determine whether a given positive integer is a perfect
// number. A perfect number is a number that is equal to the sum of all its positive divisors other
// than itself. For example, 6 is a perfect number because 1 + 2 + 3 = 6.

// Use this function in another function that will find all perfect numbers in an interval from the
// first to the second argument of this function. Print each perfect number together with its
// divisor sum. Print three results per line, in a well aligned table.

#include <iomanip>
#include <iostream>

using namespace std;

// function prototypes
bool isPerfect(int num);
void printPerfectNumberInRange(int min, int max);

// global declarations of constants
const int INTERVAL_MIN = 1;
const int INTERVAL_MAX = 10000;

int main()
{
    printPerfectNumberInRange(INTERVAL_MIN, INTERVAL_MAX);
    return 0;
}

bool isPerfect(int num)
{
    if (num <= 1)
    {
        return false;
    }

    int perfect{1};

    for (int i{2}; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            perfect += i;
        }
    }

    return perfect == num;
}

void printPerfectNumberInRange(int min, int max)
{
    int count{};

    for (int i{min}; i <= max; ++i)
    {
        if (isPerfect(i))
        {
            cout << i << "(sum = " << i << ")" << setw(10);

            ++count;

            if (count == 3)
            {
                cout << '\n';
                count = 0;
            }
        }
    }

    if (count != 0)
    {
        cout << '\n';
    }
}
