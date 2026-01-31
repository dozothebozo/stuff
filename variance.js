// This program finds the sample variance of the number of fatal airline accidents from 1997 to 2005.
// Data Sample Source: National Saftey Council.

function getDataValueCount(sample) {
  const keys = Object.keys(sample);
  let n = 0;

  for (let i = 0; i < keys.length; i++) {
    n += sample[keys[i]];
  }

  return n;
}

function getSampleMedian(sample) {
  const keys = Object.keys(sample)
  const n = keys.length;

  if (n % 2 != 0) {
    return sample[keys[(n + 1) / 2]];
  }

  return 0.5 * ((sample[keys[n / 2]]) + (sample[keys[n + 1 / 2]]));
}

function getSampleMean(total, sample) {
  return total / Object.keys(sample).length;
}

function getSampleVariance(sample, mean) {
  const keys = Object.keys(sample);
  let s2 = 0;

  for (let i = 0; i < keys.length; i++) {
    let x = sample[keys[i]];
    s2 += (x - mean) ** 2;
  }

  s2 /= keys.length - 1

  return s2;
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

const totalAccidents = getDataValueCount(accidents);
const mean = getSampleMean(totalAccidents, accidents);
const median = getSampleMedian(accidents);
const sampleVariance = getSampleVariance(accidents, mean);


// 3. print the results.

console.log(`Frequency Table: \n${JSON.stringify(accidents)}\n`);
console.log(`Total number of airline accidents from 1997 - 2005: ${totalAccidents}\n`);
console.log(`Mean: ${mean}\n`);
console.log(`Median: ${median}\n`);
console.log(`Sample variance: ${sampleVariance}`);
