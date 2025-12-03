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
  const K = input[0];
  const answer = new Array;
  for (let i = 1; i <= K; i++) {
    if (input[i]) {
        answer.push(input[i]);
    } else {
        answer.pop();
    }
  }

  return answer.reduce((acc, cur) => acc+cur, 0);
}

console.log(solution(input));
