#include "Temperature.h"
#include <cassert>
#include <iomanip>
#include <iostream>

Temperature::Temperature(double celsius)
{
    setCelsius(celsius);
}

void Temperature::setCelsius(double value)
{
    assert(value >= -273.15 && "Celsius cannot go below absolute zero");

    if (value >= -273.15)
    {
        m_celsius = value;
    }
    else
    {
        std::cout << "Celsius cannot go below absolute zero. Value rejected.\n";
    }
}

void Temperature::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Celsius: " << m_celsius << '\n';
    std::cout << "Fahrenheit: " << getFahrenheit() << '\n';
    std::cout << "Kelvin: " << getKelvin() << '\n';
}
