// Postal Bar Code
// Write a program that asks the user for a five-digit zip code and prints
// the corresponding postal bar code.
//
// Rules and Specifications:
// 1) Prompt the user to enter a five-digit zip code.
// 2) Encode each of the five digits using the postal bar code scheme.
// 3) Before the encoded digits, print a full-height frame bar.
// 4) After the five encoded digits, compute and encode a check digit.
// 5) The check digit is chosen so that the sum of all five zip-code digits
//    plus the check digit is a multiple of 10.
// 6) After the check digit, print a final full-height frame bar.
// 7) Use ':' to represent a half bar.
// 8) Use '|' to represent a full bar.
//
// Encoding Information:
// 1) Each digit is encoded using five bars.
// 2) The bar positions have weights 7, 4, 2, 1, 0.
// 3) A 0 in the table means a half bar, and a 1 means a full bar.
// 4) The digit encodings are:
//
//    1 = 00011
//    2 = 00101
//    3 = 00110
//    4 = 01001
//    5 = 01010
//    6 = 01100
//    7 = 10001
//    8 = 10010
//    9 = 10100
//    0 = 11000
//
// Example:
// If the zip code is 95014, the sum of the digits is 19, so the check digit
// is 1 to make the total 20.
//
// Example Output:
// |:|::|:::||::|:|::|::|:|:|::|||
