function linearSearch(nums: Number[], n: Number): boolean {
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === n) {
      return true
    }
  }
  return false;
}

let nums: Number[] = [1, 60, 21, 3, 15, 31, 5, 678, 6, 8, 10, 14, 23, 51]

console.log(linearSearch(nums, 10))
console.log(linearSearch(nums, 23))
console.log(linearSearch(nums, 52))
console.log(linearSearch(nums, 13))
console.log(linearSearch(nums, 3))
console.log(linearSearch(nums, 671))