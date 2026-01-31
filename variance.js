// This program finds the sample variance of the number of fatal airline accidents from 1997 to 2005.
// Data Sample Source: National Safety Council.

function getDataValueTotal(sample) {
  const values = Object.values(sample);
  let sum = 0;

  for (let i = 0; i < values.length; i++) {
    sum += values[i];
  }

  return sum;
}

function getSampleMedian(sample) {
  const values = Object.values(sample).slice().sort((a, b) => a - b);
  const n = values.length;

  if (n % 2 !== 0) {
    return values[((n + 1) / 2) - 1];
  }

  return (values[n / 2 - 1] + values[n / 2]) / 2;
}

function getSampleMean(total, sample) {
  return total / Object.keys(sample).length;
}

function getSampleVariance(sample, mean) {
  const values = Object.values(sample);
  let s2 = 0;

  for (let i = 0; i < values.length; i++) {
    const x = values[i];
    s2 += (x - mean) ** 2;
  }

  return s2 / (values.length - 1);
}

const accidents = {
  "1997": 25,
  "1998": 20,
  "1999": 21,
  "2000": 18,
  "2001": 13,
  "2002": 13,
  "2003": 7,
  "2004": 9,
  "2005": 18
};

const totalAccidents = getDataValueTotal(accidents);
const mean = getSampleMean(totalAccidents, accidents);
const median = getSampleMedian(accidents);
const sampleVariance = getSampleVariance(accidents, mean);


// 3. print the results.

console.log(`Frequency Table: \n${JSON.stringify(accidents)}\n`);
console.log(`Total number of airline accidents from 1997 - 2005: ${totalAccidents}\n`);
console.log(`Mean: ${mean}\n`);
console.log(`Median: ${median}\n`);
console.log(`Sample variance: ${sampleVariance}`);
