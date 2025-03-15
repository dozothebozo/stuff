export function linearSearch(nums: number[], n: number): number {
  if (nums.length === 0) return -1
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === n) {
      return i
    }
  }
  return -1;
}

let nums: number[] = [1, 60, 21, 3, 15, 31, 5, 678, 6, 8, 10, 14, 23, 51]

console.log(linearSearch(nums, 10))
console.log(linearSearch(nums, 23))
console.log(linearSearch(nums, 52))
console.log(linearSearch(nums, 13))
console.log(linearSearch(nums, 3))
console.log(linearSearch([], 1))