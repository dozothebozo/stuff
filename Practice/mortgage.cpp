// Suppose you want to buy a house. You take out a mortgage that requires fixed monthly repayment.
// There is also interest to pay on the principal you have borrowed. Every month the amount left to
// be repaid grows by the monthly interest rate.

// For example, suppose you borrow $60 000, pay it back at $2000 a month and the monthly interest
// rate is 0.8%. After one month, the principal has grown to $60480 because of interest (0.8% of
// $60000 is $480), then immediately fallen to $58480 because of the first monthly repayment of
// $2000. After the second month, the principal grows to $58947.84 and then falls to $56 947.84.
// This continues month after month, until after the 34th month there is only $878.22 outstanding.
// The 35th repayment is just $885.25 (the outstanding amount, plus the last month’s interest),
// clearing the mortgage.

// Write a C++ program function to calculate and print the mortgage payment schedule.
