// Regression Line
// Write a program that plots a regression line: that is, the line with the
// best fit through a collection of points.
//
// Rules and Specifications:
// 1) First ask the user to specify the data points by clicking on them in
//    the graphics window.
// 2) To find the end of the input, place a small rectangle labeled "Stop"
//    at the bottom of the screen. When the user clicks inside that rectangle,
//    then stop gathering input.
// 3) The regression line is the line with equation:
//    y = y_mean + m * (x - x_mean)
// 4) Where the slope 'm' is calculated as:
//    m = (sum(x_i * y_i) - n * x_mean * y_mean) / (sum(x_i^2) - n * (x_mean^2))
// 5) In these formulas:
//    - x_mean is the average of the x-coordinates.
//    - y_mean is the average of the y-coordinates.
//    - n is the total number of data points entered.
//    - sum(x_i * y_i) is the sum of the products of each point's coordinates.
//    - sum(x_i^2) is the sum of the squares of the x-coordinates.
