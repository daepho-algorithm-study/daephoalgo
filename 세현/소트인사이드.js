const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("")
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {

  input.sort((a, b) => b - a);
  const answer = input.join("");
  return answer;
}

console.log(solution(input));
