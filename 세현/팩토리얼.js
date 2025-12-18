const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", 'utf-8')
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const rng = Array.from({length:input[0]}, (v, i) => i+1);
  return rng.reduce((acc, cur) => acc*cur, 1);
}

console.log(solution(input));
