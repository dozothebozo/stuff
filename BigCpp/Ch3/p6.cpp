// Write a program that converts a positive integer into the Roman number system.
// Roman numerals use the digits:
//
// I    1
// V    5
// X    10
// L    50
// C    100
// D    500
// M    1000
//
// Numbers are formed according to these rules:
// 1) Only numbers up to 3,999 are represented.
// 2) As in the decimal system, the thousands, hundreds, tens, and ones are expressed separately.
// 3) The numbers 1 to 9 are expressed as:
//      I     1
//      II    2
//      III   3
//      IV    4
//      V     5
//      VI    6
//      VII   7
//      VIII  8
//      IX    9
//
// Same pattern as 1-9, but with different symbols:
// - Ones:      I, V, X
// - Tens:      X, L, C
// - Hundreds:  C, D, M
// - Thousands: M (up to MMM for 3000)
//
// Example:
//
// Computer: Please enter a positive integer (1..3999):
// User: 1978
// Computer: The Roman numeral is MCMLXXVIII
