const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0][0];
  const divisors = input[1];
  divisors.sort((a,b) => a-b)
  return divisors[0]*divisors[N-1];
}

console.log(solution(input));
