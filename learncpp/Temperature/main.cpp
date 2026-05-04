/*
    Create a class named Temperature that stores a temperature in Celsius.

    Data member:
    - celsius

    Required behavior:
    - Constructor that accepts a Celsius value.
    - getCelsius() const
    - getFahrenheit() const
    - getKelvin() const
    - setCelsius(double value)
    - print() const

    Rules:
    - Celsius cannot go below absolute zero: -273.15.
    - If the user tries to set a temperature below absolute zero, reject it.

    Example:

        Temperature temp{25.0};

        temp.print();

    Possible output:

        Celsius: 25.00
        Fahrenheit: 77.00
        Kelvin: 298.15

    Hint:

    Formula reminders:
    Fahrenheit = Celsius * 9 / 5 + 32
    Kelvin = Celsius + 273.15
*/

#include "Temperature.h"

int main()
{
    Temperature today{25};
    today.print();
    return 0;
}
