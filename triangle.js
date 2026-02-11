// Write a program that prints a triangle of digits, as shown in the examples below.
//
// Example 1:
// Computer: How many rows?
// User: 4
// Computer:
//
// 1 2 3 4
//   1 2 3
//     1 2
//       1
//
// Example 2:
// Computer: How many rows?
// User: 6
// Computer:
//
// 1 2 3 4 5 6
//   1 2 3 4 5
//     1 2 3 4
//       1 2 3
//         1 2
//           1

function getRows() {
  const rows = Number(prompt("How many rows?"));
  return rows;
}

function printTriangle(n) {
  for (let i = 1; i <= n; i++) {
    let row = "";

    for (let j = 1; j <= i - 1; j++) {
      row += " ";
    }

    for (let k = 1; k <= (n + 1) - i; k++) {
      row += `${k}`;
    }

    console.log(row);

  }
}

const rows = getRows();
printTriangle(rows);
