// Write a unit conversion program using standard conversion factors.
//
// Rules and Specifications:
// 1) Ask the user for the unit to convert from. Valid inputs are:
//    fl. oz, gal, oz, lb, in, ft, mi
// 2) Ask the user for the unit to convert to. Valid inputs are:
//    ml, l, g, kg, mm, cm, m, km
// 3) Reject incompatible conversions (e.g., attempting to convert
//    volume to distance, such as gal -> km).
// 4) Ask the user for the numeric value to be converted.
// 5) Calculate and display the formatted result.
//
// Example:
//
// Computer: Convert from?
// User: gal
// Computer: Convert to?
// User: ml
// Computer: Value?
// User: 2.5
// Computer: 2.5 gal = 9462.5 ml

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

void ignoreLine();
bool restoreStream();
std::string getString(const std::string& prompt);
double getDouble(const std::string& prompt);
void getConversionInput(std::string& from, std::string& to, double& value, int& category);
double getFactorToBase(const std::string& unit, int category);
double unitConversion(const std::string& from, const std::string& to, double value, int category);

enum Category
{
    Invalid,
    Volume,
    Mass,
    Length
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool restoreStream()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(1);
        }

        std::cin.clear();
        ignoreLine();
        return true;
    }

    return false;
}

std::string getString(const std::string& prompt)
{
    while (true)
    {
        std::string s{};
        std::cout << prompt;
        std::getline(std::cin >> std::ws, s);

        if (restoreStream())
        {
            std::cout << "Invalid input, please try again.\n";
            continue;
        }

        return s;
    }
}

double getDouble(const std::string& prompt)
{
    while (true)
    {
        double d{};
        std::cout << prompt;
        std::cin >> d;

        if (restoreStream())
        {
            std::cout << "Invalid input, please try again.\n";
            continue;
        }

        ignoreLine();
        return d;
    }
}

int getCategory(const std::string& unit)
{
    if (unit == "fl. oz" || unit == "gal" || unit == "ml" || unit == "l")
    {
        return Volume;
    }
    else if (unit == "oz" || unit == "lb" || unit == "g" || unit == "kg")
    {
        return Mass;
    }
    else if (unit == "in" || unit == "ft" || unit == "mi" || unit == "mm" || unit == "cm" ||
             unit == "m" || unit == "km")
    {
        return Length;
    }
    else
    {
        return Invalid;
    }
}

void getConversionInput(std::string& from, std::string& to, double& value, int& category)
{
    while (true)
    {
        from = getString("Convert from? ");
        to = getString("Convert to? ");

        int fromCategory{getCategory(from)};
        int toCategory{getCategory(to)};

        if (fromCategory == Invalid || toCategory == Invalid)
        {
            std::cout << "Invalid unit. Try again.\n";
            continue;
        }

        if (fromCategory != toCategory)
        {
            std::cout << "Incompatible conversion. Try again.\n";
            continue;
        }

        value = getDouble("Value? ");
        category = fromCategory;
        return;
    }
}

double getFactorToBase(const std::string& unit, int category)
{
    if (category == Volume)
    {
        if (unit == "fl. oz")
        {
            return 29.5735;
        }
        else if (unit == "gal")
        {
            return 3785.0;
        }
        else if (unit == "ml")
        {
            return 1.0;
        }
        else
        {
            return 1000.0; // l
        }
    }
    else if (category == Mass)
    {
        if (unit == "oz")
        {
            return 28.3495;
        }
        else if (unit == "lb")
        {
            return 453.592;
        }
        else if (unit == "g")
        {
            return 1.0;
        }
        else
        {
            return 1000.0; // kg
        }
    }
    else
    {
        if (unit == "in")
        {
            return 0.0254;
        }
        else if (unit == "ft")
        {
            return 0.3048;
        }
        else if (unit == "mi")
        {
            return 1609.34;
        }
        else if (unit == "mm")
        {
            return 0.001;
        }
        else if (unit == "cm")
        {
            return 0.01;
        }
        else if (unit == "m")
        {
            return 1.0;
        }
        else
        {
            return 1000.0; // km
        }
    }
}

double unitConversion(const std::string& from, const std::string& to, double value, int category)
{
    double fromFactor{getFactorToBase(from, category)};
    double toFactor{getFactorToBase(to, category)};

    double baseValue{value * fromFactor};
    return baseValue / toFactor;
}

int main()
{
    std::string from{};
    std::string to{};
    double fromValue{};
    int category{Invalid};

    getConversionInput(from, to, fromValue, category);

    double convertedValue{unitConversion(from, to, fromValue, category)};

    std::cout << fromValue << ' ' << from << " = " << convertedValue << ' ' << to << '\n';

    return 0;
}
