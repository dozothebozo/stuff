// This program accepts a stream of data values from the user and calculates the sum and average then prints to the console.

function getDataValues() {
  let res = [];
  let input;

  while (input !== "/") {
    input = prompt("Enter a data value (enter / to quit) :");
    if (Number(input)) res.push(Number(input));
  }

  return res;
}

function sum(sample) {
  let sum = 0;

  for (let i = 0; i < sample.length; i++) {
    sum += sample[i];
  }

  return sum;
}

function mean(sample, sum) {
  return sum / sample.length;
}

const dataValues = getDataValues();
const total = sum(dataValues);
const average = mean(dataValues, total);

console.log(`\nData Sample: {${dataValues}}\n`);
console.log(`Sum: ${total}\n`);
console.log(`Mean: ${average}`);
