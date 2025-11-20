const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" "));

// console.log(input);

function solution(input) {
  const arr = input.slice(1);
  arr.sort((a, b) => Number(a[0])-Number(b[0]))

  return arr.map((row) => row.join(" "));
}

console.log(solution(input).join('\n'));
