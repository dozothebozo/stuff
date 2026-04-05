// The Fantastic Floral Company sells to wholesale and retail buyers. A buyer is considered a
// wholesale buyer if he or she is assigned a resale number, otherwise the buyer is considered a
// retail buyer. Retail buyers pay 6% tax. Wholesale buyers buy at no tax and receive discounts
// according to the following table:

// Up to $100.00: 2%
// From $100.01 to $500.00: 5%
// Above $500.00: 10%

// Write a function amountOwed that will calculate and return how much a customer owes the company.
// Then write a main program that will input the relevant data for a number of customers, call the
// function for each customer, and print a well aligned table showing customer type, purchase
// amount, and amount owed.

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// function prototypes
void ignoreLine();
bool recoverStream();
double amountOwed(double purchaseAmount, bool isWholesaleBuyer);
int getInteger(const string& prompt);
double getDouble(const string& prompt);
bool getBoolean(const string& prompt);

// global declarations of constants
const int IGNORE_SIZE = 1000;
const double RETAIL_TAX = 0.06;
const double DISCOUNT_AMOUNT_LOW = 100.00;
const double DISCOUNT_AMOUNT_MID = 500.00;
const double DISCOUNT_RATE_LOW = 0.02;
const double DISCOUNT_RATE_MID = 0.05;
const double DISCOUNT_RATE_HIGH = 0.10;

int main()
{
    char choice;

    do
    {
        int customers{getInteger("Enter the number of customers: ")};

        cout << fixed << showpoint << setprecision(2);

        for (int i{1}; i <= customers; i++)
        {
            cout << "\nCustomer " << i << '\n';

            double purchaseAmount{getDouble("Enter purchase amount: $")};
            bool isWholesaleBuyer{
                getBoolean("Is the customer a wholesale buyer with a resale number? (y/n): ")};

            string customerType{"Retail"};
            if (isWholesaleBuyer)
            {
                customerType = "Wholesale";
            }

            double owed{amountOwed(purchaseAmount, isWholesaleBuyer)};

            cout << left << setw(16) << "Customer Type:" << customerType << '\n';
            cout << left << setw(16) << "Purchase:" << '$' << purchaseAmount << '\n';
            cout << left << setw(16) << "Amount Owed:" << '$' << owed << '\n';
        }

        cout << "\nWould you like to do it again? (y/n): ";
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

double amountOwed(double purchaseAmount, bool isWholesaleBuyer)
{
    if (isWholesaleBuyer)
    {
        double discount{};

        if (purchaseAmount <= DISCOUNT_AMOUNT_LOW)
        {
            discount = purchaseAmount * DISCOUNT_RATE_LOW;
        }
        else if (purchaseAmount <= DISCOUNT_AMOUNT_MID)
        {
            discount = (DISCOUNT_AMOUNT_LOW * DISCOUNT_RATE_LOW) +
                       ((purchaseAmount - DISCOUNT_AMOUNT_LOW) * DISCOUNT_RATE_MID);
        }
        else
        {
            discount = (DISCOUNT_AMOUNT_LOW * DISCOUNT_RATE_LOW) +
                       ((DISCOUNT_AMOUNT_MID - DISCOUNT_AMOUNT_LOW) * DISCOUNT_RATE_MID) +
                       ((purchaseAmount - DISCOUNT_AMOUNT_MID) * DISCOUNT_RATE_HIGH);
        }

        return purchaseAmount - discount;
    }

    return purchaseAmount * (1 + RETAIL_TAX);
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
