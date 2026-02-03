// This program computes some sequences.

// 1 + 1/2 + 1/3 + 1/4 + ...
function seq1() {
  let total = 0;
  for (let i = 1; i <= 25; i++) {
    total += 1 / i;
  }
  console.log(total);
}

// const + 2/3 + 3/5 + 4/7 + 5/9 + 6/11 + ...
//
// i = 1   i + 1 / 2i + 1    = 2/3
// i = 2   i + 1 / 2i + 1    = 3/5
// i = 3   i + 1 / 2i + 1    = 4/7
// i = 4   i + 1 / 2i + 1    = 5/9
// ...

function seq2() {
  const value = Number(prompt("Enter an inital value:"));
  let ans = value;
  for (let i = 1; i <= 4; i++) {
    ans += (i + 1) / (2 * i + 1);
  }
  console.log(ans);
}

// e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ...
function seq3() {
  let e = 1;
  let factorial = 1;
  for (let i = 1; i <= 20; i++) {
    factorial *= i;
    e += 1 / factorial;
  }
  console.log(e);
}

// e^x = 1 + x/1! + x^2/2! + x^3/3! + 4^x/4! + ...
function seq4() {
  let ans = 1;
  let factorial = 1;
  let x = Number(prompt("Enter an exponent:"));
  for (let i = 1; i <= 20; i++) {
    factorial *= i;
    ans += (x ** i) / factorial;
  }
  console.log(ans);
}

// pie = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
function seq5() {
  let pie = 0;
  let s = 1;
  for (let i = 1; i <= 200000; i += 2) {
    pie += (s) * (1 / i);
    s *= -1;
  }
  pie *= 4;
  console.log(pie);
}

// seq1();
// seq2();
// seq3();
// seq4();
// seq5();
