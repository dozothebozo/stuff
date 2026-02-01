// This program calculates n! using accumulation by multiplication.

function factorial(n) {
  let res = 1;

  if (n === 0 || n === 1) return res;

  for (let i = 2; i <= n; i++) {
    res *= i;
  }

  return res;
}

const n = Number(prompt("Enter a non-negative integer:"));
const res = factorial(n);

n >= 0 ? console.log(`${n}! is ${res}.`) : console.log("non-negative inputs are invalid.");
