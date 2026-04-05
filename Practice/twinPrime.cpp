// Write a function isPrime that will determine whether a given integer is prime. A prime number is
// a number that can only be divided by itself and 1 without remainders. Use this function in
// another function that will find all pairs of “twin prime numbers” in an interval from the first
// to the second argument of this function (for example, from 1 to 500). A “twin prime numbers” pair
// is a pair of prime numbers that differ by 2. For example, 3 and 5 are twin prime numbers, 5 and 7
// are twin prime numbers, etc. Print each pair of twin prime numbers in parentheses. Print four
// pairs per line, in a well aligned table.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// function prototypes
bool isPrime(int num);
vector<int> getPrimeInRange(int min, int max);
void printTwinPrime(vector<int>& primes);

// global declarations of constants
const int INTERVAL_MIN{1};
const int INTERVAL_MAX{10000};
const int ALIGN{4}; // four pairs per line

int main()
{
    vector<int> primes{getPrimeInRange(INTERVAL_MIN, INTERVAL_MAX)};
    printTwinPrime(primes);
    return 0;
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    if (num == 2)
    {
        return true;
    }

    if (num % 2 == 0)
    {
        return false;
    }

    for (int i{3}; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> getPrimeInRange(int min, int max)
{
    vector<int> primes{};

    for (int i{min}; i <= max; ++i)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    return primes;
}

void printTwinPrime(vector<int>& primes)
{
    int count{};

    for (unsigned int i{0}; i < primes.size() - 1; ++i)
    {
        if (primes[i + 1] - primes[i] == 2)
        {
            cout << '(' << primes[i] << ',' << primes[i + 1] << ')';
            cout << setw(6) << ' ';

            ++count;

            if (count == ALIGN)
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
