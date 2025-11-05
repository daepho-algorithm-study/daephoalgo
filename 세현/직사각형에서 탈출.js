const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  let answer = 0;
  const [x, y, w, h] = input;
  answer = Math.min(Math.abs(x - w), Math.abs(y - h), x, y);
  return answer;
}

console.log(solution(input));
