const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
//   .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const arr = input.slice(1);
  arr.sort((a, b) => {
    if (a.length === b.length) {
        return a.localeCompare(b)
    } else {
        return a.length - b.length;
    }
  })

  const answer = arr.filter((value, idx) => idx === 0 || value !== arr[idx - 1]);
  return answer;
}

console.log(solution(input).join('\n'));
