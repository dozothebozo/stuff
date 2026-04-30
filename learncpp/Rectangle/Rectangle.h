#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  private:
    double m_width{0.0};
    double m_height{0.0};

  public:
    explicit Rectangle(double width = 0.0, double height = 0.0);

    double width() const
    {
        return m_width;
    }

    double height() const
    {
        return m_height;
    }

    void setWidth(double width);

    void setHeight(double height);

    double area() const;

    double perimeter() const;

    bool isSquare() const;

    void print() const;
};

#endif // !RECTANGLE_H
