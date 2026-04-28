/*
    Create a class named Rectangle.

    Data members:
    - width
    - height

    Required behavior:
    - Constructor that initializes width and height.
    - setWidth(double width)
    - setHeight(double height)
    - area() const
    - perimeter() const
    - isSquare() const
    - print() const

    Also write a non-member function:

        const Rectangle& largerArea(const Rectangle& first,
                                    const Rectangle& second);

    The function should return the rectangle with the larger area.

    Example:

        Rectangle r1{4.0, 5.0};
        Rectangle r2{3.0, 8.0};

        const Rectangle& bigger{largerArea(r1, r2)};
        bigger.print();

    Possible output:

        Width: 3.00
        Height: 8.00
        Area: 24.00
        Perimeter: 22.00
*/
