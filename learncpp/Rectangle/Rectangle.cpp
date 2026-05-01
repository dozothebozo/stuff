#include "Rectangle.h"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double height) : m_width{width}, m_height{height}
{
    assert(width >= 0.0 && "The width of a Rectangle cannot be negative.");
    assert(height >= 0.0 && "The height of a Rectangle cannot be negative.");
}

void Rectangle::setWidth(double width)
{
    assert(width >= 0.0 && "The width of a Rectangle cannot be negative.");
    m_width = width;
}

void Rectangle::setHeight(double height)
{
    assert(height >= 0.0 && "The height of a Rectangle cannot be negative.");
    m_height = height;
}

double Rectangle::area() const
{
    return m_width * m_height;
}

double Rectangle::perimeter() const
{
    return 2.0 * m_width + 2.0 * m_height;
}

bool Rectangle::isSquare() const
{
    return (m_width == m_height) ? true : false;
}

void Rectangle::print() const
{
    std::cout << "Rectangle (" << m_width << ", " << m_height << "): \n";
    std::cout << "width: " << m_width << '\n';
    std::cout << "height: " << m_height << '\n';
    std::cout << "area: " << area() << '\n';
    std::cout << "perimeter: " << perimeter() << '\n';
}

const Rectangle& largerArea(const Rectangle& first, const Rectangle& second)
{
    return (first.area() >= second.area()) ? first : second;
}
