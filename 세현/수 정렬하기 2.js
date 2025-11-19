const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
    N = input[0];
    nums = input.slice(1);
    nums.sort((a,b) => a - b);
    
/*
퀵소트 써서 풀어보려고 했는데 시간 초과로 실패
----------------------------------------------------------------------------------------
  function quickSort(arr, left, right) {
    if (left < right) {
        p_idx = partition(arr, left, right);

        quickSort(arr, left, p_idx-1);
        quickSort(arr, p_idx+1, right);
    }
  }

  function partition(arr, left, right) {
    const pivot = arr[right];
    let i = left - 1;
    for (let j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i += 1;
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    [arr[i+1], arr[right]] = [arr[right], arr[i+1]];

    return i+1;
  }
---------------------------------------------------------------------
*/
//   quickSort(nums, 0, N-1);
  return nums;
}

console.log(solution(input).join('\n'));
