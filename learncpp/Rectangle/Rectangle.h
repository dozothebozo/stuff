#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  private:
    double m_width{0.0};
    double m_height{0.0};

  public:
    explicit Rectangle(double width = 0.0, double height = 0.0);

    void setWidth(double width)
    {
        m_width = width;
    }

    void setHeight(double height)
    {
        m_height = height;
    }

    double area() const;

    double perimeter() const;

    bool isSquare() const;

    void print() const;
};

#endif // !RECTANGLE_H
