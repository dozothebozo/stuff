// This program calculates the Fibonacci Sequence.

function fibonacci(n) {
  if (n < 0) return;
  if (n === 1 || n === 0) return 1;

  let fib = [1, 1];

  for (let i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib[n];
}

const n = Number(prompt("Enter the nth term:"));
console.log(fibonacci(n));
