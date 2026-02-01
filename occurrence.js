function getNumberSequence() {
  const n = prompt("Enter sequence length:");
  let res = [];

  for (let i = 1; i <= n; i++) {
    const num = Number(prompt(`Enter number ${i}/${n}:`));
    res.push(num);
  }

  return res;
}

function findOccurrence(seq) {
  let res = {};

  for (let i = 0; i < seq.length; i++) {
    const num = seq[i];

    if (num < 0) {
      res[i + 1] = num; // {index: negative number}
    }
  }

  return res;
}

const sequence = getNumberSequence();
const negativeNumOccurrence = findOccurrence(sequence);
const indices = Object.keys(negativeNumOccurrence);
const values = Object.values(negativeNumOccurrence);
const length = values.length

if (length === 0) {
  console.log("No negative numbers were entered.")
} else {
  console.log(`The first negative number entered is ${values[0]} at index ${indices[0]}.`);
  console.log(`The last negative number entered is ${values[length - 1]} at index ${indices[length - 1]}.`);
}
