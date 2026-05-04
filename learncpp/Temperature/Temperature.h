#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature
{
  private:
    double m_celsius{0.0};

  public:
    explicit Temperature(double celsius = 0.0);

    double getCelsius() const
    {
        return m_celsius;
    }

    double getFahrenheit() const
    {
        return m_celsius * 9 / 5 + 32;
    }

    double getKelvin() const
    {
        return m_celsius + 273.15;
    }

    void setCelsius(double value);

    void print() const;
};

#endif // !TEMPERATURE_H
