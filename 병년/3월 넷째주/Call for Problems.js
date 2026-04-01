const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const isOdd = (num) => {
  if (num % 2 === 0) {
    return 0;
  } else {
    return 1;
  }
};
const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  let answer = 0;
  for (let i = 0; i < N; i++) {
    let num = Number(input[idx++]);
    answer += isOdd(num);
  }
  console.log(answer);
};
solution(input);
