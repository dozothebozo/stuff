// Write a program that implements a recursive factorial function.
//
// Rules and Specifications:
// 1) Recall that the factorial of a nonnegative integer n is defined as:
//    n! = 1 x 2 x 3 x ... x n
// 2) Implement the factorial function recursively using these definitions:
//    - n! = (n - 1)! x n
//    - 0! = 1
// 3) The function should take a nonnegative integer as its argument.
// 4) The function should return the factorial of that integer.
//
// Example:
// 3! = 3 x 2 x 1 = 6

#include <cstdlib>
#include <iostream>
#include <limits>

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

int getInteger()
{
    while (true)
    {
        int x{};
        std::cout << "Enter a nonnegative integer: ";
        std::cin >> x;

        if (recoverStream() || x < 0)
        {
            std::cout << "Invalid Input. Try again.\n";
            continue;
        }

        return x;
    }
}

// n! = (n - 1)! x n
// 0! = 1
unsigned long long factorial(unsigned long long n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int num{getInteger()};
    std::cout << num << "! = " << factorial(static_cast<unsigned long long>(num)) << '\n';
    return 0;
}
