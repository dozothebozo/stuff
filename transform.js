// Transform an integer digit by digit:
// for each digit, add 5 and take modulo 10.
//
// Example:
//
// Computer: Please enter a non-negative integer:
// User: 25964
// Computer: The modified number is 70419.

function getInteger() {
  let num = Number(prompt("Please enter a non-negative number:"));
  return num;
}

function transform(num) {
  let newNum = 0;
  let weight = 1;

  // iterate on digits from right to left
  while (num > 0) {
    let lastDigit = num % 10;
    let digit = (lastDigit + 5) % 10;

    // Remove current digit from num
    num = Math.trunc(num / 10);

    digit *= weight;
    newNum += digit;
    weight *= 10;
  }

  return newNum;
}

const num = getInteger();
const newNum = transform(num);
