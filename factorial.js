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

n >= 0 ? console.log(`${n}! is ${factorial(n)}.`) : console.log("negative inputs are invalid.");
