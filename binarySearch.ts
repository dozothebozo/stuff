export function binarySearch(nums: number[],  n: number): boolean {
  if (nums.length === 0) return false;

  let leftIndex: number = 0;
  let rightIndex: number = nums.length - 1;

  while(leftIndex <= rightIndex) {
    let middleIndex: number = (leftIndex + rightIndex) / 2;

    if (nums[middleIndex] === n) {
      return true;
    } else if (nums[middleIndex] < n) {
      leftIndex = middleIndex;
    } else {
      rightIndex = middleIndex
    }
  }

  return false;
}

let nums: number[] = [1, 2, 3, 4, 5, 6];
console.log(binarySearch(nums, 3));
console.log(binarySearch(nums, 4));
console.log(binarySearch(nums, 2));
console.log(binarySearch(nums, 7));
console.log(binarySearch([], 2));

