// Exercise P3.17: Mean and standard deviation.
// Write a program that reads a set of floating-point data values from the input.
// When the end of file is reached, print out the count of the values, the average,
// and the standard deviation.
//
// Rules and Specifications:
// 1) The average of a data set {x_1, ..., x_n} is:
//    mean = sum(x_i) / n
//    where sum(x_i) = x_1 + ... + x_n is the sum of the input values.
// 2) The standard deviation is typically calculated using the formula:
//    s = sqrt( sum((x_i - mean)^2) / (n - 1) )
// 3) However, this formula is not suitable for this task. By the time the program
//    has computed the mean, the individual x_i values are long gone.
// 4) Until you know how to save these values, use the numerically less stable formula:
//    s = sqrt( (sum(x_i^2) - (1/n) * (sum(x_i))^2) / (n - 1) )
// 5) You can compute this quantity efficiently by keeping track of three things
//    as you process the input values:
//    - The count of values (n)
//    - The sum of the values (sum(x_i))
//    - The sum of the squares of the values (sum(x_i^2))

#include <cmath>
#include <iostream>

int main() {
  int count{0};
  double sum{0.0};
  double sumsq{0.0};
  double x{};

  std::cout << "Enter data values (Ctrl+D or Ctrl+Z to end):\n";

  while (std::cin >> x) {
    sum += x;
    sumsq += x * x;
    ++count;
  }

  if (count == 0) {
    std::cout << "\nNo data was provided.\n";
    return 1;
  }

  double mean{sum / count};

  std::cout << "count: " << count << '\n';
  std::cout << "sum: " << sum << '\n';
  std::cout << "mean: " << mean << '\n';

  if (count < 2) {
    std::cout << "sd requires at least 2 data points.\n";
  } else {
    double sd{std::sqrt((sumsq - (1.0 / count) * (sum * sum)) / (count - 1))};
    std::cout << "sd: " << sd << '\n';
  }

  return 0;
}
