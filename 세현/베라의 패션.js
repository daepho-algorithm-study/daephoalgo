const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", 'utf-8')
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {

  return input[0]*(input[0]-1);
}

console.log(solution(input));
