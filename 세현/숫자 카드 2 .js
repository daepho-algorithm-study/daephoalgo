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
  const sang = input[1], nums = input[3];
  const nummap = new Map(nums.map((value) => [value, 0]));
  
  sang.forEach((e) => {
    if (nummap.has(e)) {
        nummap.set(e, nummap.get(e)+1)
    }
  });

  const answer = [];
  nums.forEach((e) => answer.push(nummap.get(e)))
  
  return answer.join(' ');
}

console.log(solution(input));
