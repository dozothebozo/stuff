// Suppose you want to buy a house. You take out a mortgage that requires fixed monthly repayment.
// There is also interest to pay on the principal you have borrowed. Every month the amount left to
// be repaid grows by the monthly interest rate.

// For example, suppose you borrow $60 000, pay it back at $2000 a month and the monthly interest
// rate is 0.8%. After one month, the principal has grown to $60480 because of interest (0.8% of
// $60000 is $480), then immediately fallen to $58480 because of the first monthly repayment of
// $2000. After the second month, the principal grows to $58947.84 and then falls to $56 947.84.
// This continues month after month, until after the 34th month there is only $878.22 outstanding.
// The 35th repayment is just $885.25 (the outstanding amount, plus the last month’s interest),
// clearing the mortgage.

// Write a C++ program function to calculate and print the mortgage payment schedule.

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
double getDouble(const string& prompt);
void printMortgagePaymentSchedule(double loan, double rate, double payment);

// global declarations of constants
const int IGNORE_SIZE = 1000;

int main()
{
    char choice;

    do
    {
        double loan{};
        double rate{};
        double payment{};

        do
        {
            loan = getDouble("Enter principal: ");

            if (loan <= 0)
            {
                cout << "Principal must be greater than 0. Please try again.\n";
            }
        } while (loan <= 0);

        do
        {
            rate = getDouble("Enter monthly interest rate (%): ");

            if (rate < 0)
            {
                cout << "Interest rate cannot be negative. Please try again.\n";
            }
        } while (rate < 0);

        rate /= 100;

        do
        {
            payment = getDouble("Enter monthly repayment: ");

            if (payment <= 0)
            {
                cout << "Payment must be greater than 0. Please try again.\n";
            }
            else if (payment <= loan * rate)
            {
                cout << "Payment is too small. It must be greater than the first month's "
                        "interest.\n";
            }
        } while (payment <= 0 || payment <= loan * rate);

        printMortgagePaymentSchedule(loan, rate, payment);

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

void printMortgagePaymentSchedule(double loan, double rate, double payment)
{
    int month{1};
    double actualPayment{payment};

    cout << '\n';
    cout << fixed << setprecision(2);
    cout << setw(8) << "Month" << setw(15) << "Repayment" << setw(15) << "Remaining" << '\n';
    cout << "--------------------------------------\n";

    while (loan > 0)
    {
        loan += loan * rate;

        if (loan <= payment)
        {
            actualPayment = loan;
        }

        loan -= actualPayment;

        if (loan < 0.005)
        {
            loan = 0;
        }

        cout << setw(8) << month << setw(15) << actualPayment << setw(15) << loan << '\n';

        ++month;
    }

    cout << '\n';
}
