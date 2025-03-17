export function binarySearch(nums: number[],  n: number): number {
  if (nums.length === 0) return -1;

  let leftIndex: number = 0;
  let rightIndex: number = nums.length - 1;

  while(leftIndex <= rightIndex) {
    let middleIndex: number = leftIndex + Math.floor((rightIndex - leftIndex) / 2);

    if (n === nums[middleIndex]) {
      return middleIndex;
    } else if (n > nums[middleIndex]) {
      leftIndex = middleIndex + 1;
    } else {
      rightIndex = middleIndex - 1;
    }
  }
  return -1;
}

let nums: number[] = [1, 2, 4, 5, 6, 7, 8];
console.log(binarySearch(nums, 7));
console.log(binarySearch(nums, 4));
console.log(binarySearch(nums, 3));
console.log(binarySearch(nums, 2));
console.log(binarySearch(nums, 5));
console.log(binarySearch(nums, 6));
console.log(binarySearch(nums, 1))
console.log(binarySearch(nums, -1))
console.log(binarySearch(nums, 200))
console.log(binarySearch([], 2));