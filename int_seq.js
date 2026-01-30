function getIntSequence() {
  const n = Number(prompt("Enter integer sequence length:"));
  let res = []

  for (let i = 1; i <= n; i++) {
    const integer = Number(prompt(`Enter integer ${i}/${n}:`));
    res.push(integer);
  }

  return res;
}

function findMax(intSequence) {
  let max = intSequence[0];

  intSequence.forEach(x => {
    if (x > max) {
      max = x;
    }
  });

  return max;
}

function findMin(intSequence) {
  let min = intSequence[0];

  intSequence.forEach(x => {
    if (x < min) {
      min = x;
    }
  });

  return min;
}

const intSequence = getIntSequence();
const max = findMax(intSequence);
const min = findMin(intSequence);

console.log(`\nInteger sequence: ${intSequence}\n`);
console.log(`The largest integer in the sequence is ${max} at index ${intSequence.indexOf(max) + 1}.\n`);
console.log(`The smallest integer in the sequence is ${min} at index ${intSequence.indexOf(min) + 1}.\n`);
