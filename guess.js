// This program approximates the square root of a number using Newton's method.

function NewtonSqrt(x, guess, iterations) {
  for (let i = 0; i < iterations; i++) {
    guess = (guess + (x / guess)) / 2;
  }
  return guess;
}

let x = Number(prompt("Enter a number you want the square root of (num > 0):"));
let iterations = Number(prompt("Enter the number of iterations:"));
let guess = x / 2;

let finalGuess = NewtonSqrt(x, guess, iterations);

console.log(`The approximate square root of ${x} is ${finalGuess}`);
