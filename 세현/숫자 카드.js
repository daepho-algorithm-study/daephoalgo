const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const sang = input[1], M = input[2][0], nums = input[3];

  const cntArr = Array.from({ length: M}, () => 0);

  sang.sort((a,b) => a-b);

  function binarySearch(arr, tar) {
    let left = 0, right = arr.length - 1;
    while (left <= right) {
        const mid = Math.floor((left+right) / 2);
        if (arr[mid] === tar) return true;
        else if (arr[mid] < tar) left = mid + 1;
        else right = mid - 1;
    }
    return false;
  }

  for (let i = 0; i < M; i++) {

    if (binarySearch(sang, nums[i])) {
        cntArr[i] = 1;
    }
  }

  return cntArr.join(' ');
}

console.log(solution(input));
