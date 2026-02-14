// Write a program that:
//
// 1) First asks the user to enter today's exchange rate
//    between U.S. dollars and Japanese yen.
//    Example: If 1 U.S. dollar equals 150 yen, the user enters 150.
//
// 2) Then repeatedly asks the user to enter an amount in U.S. dollars.
//
// 3) Converts each dollar amount to yen using:
//
//       yen = dollars × exchange_rate
//
// 4) Prints the converted value.
//
// 5) Uses 0 or any negative number as a sentinel value to stop the program.
//
// Program behavior summary:
// - Read exchange rate once.
// - Continuously read dollar amounts.
// - Convert and print each result.
// - Stop when the user enters 0 or a negative value.
//
// Example:
//
// Computer: Enter today's exchange rate USD to JPY:
// User: 150
//
// Computer: Enter U.S. dollars to convert. Enter 0 or negative to stop:
// User: 10
// Computer: 10 USD = 1500 JPY
//
// Computer: Enter U.S. dollars to convert. Enter 0 or negative to stop:
// User: 0
