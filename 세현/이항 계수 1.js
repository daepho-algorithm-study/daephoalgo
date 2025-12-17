const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0][0],
    K = input[0][1];
  let N_set = 1,
    K_set = 1;
  for (let i = N; i > N - K; i--) {
    N_set *= i;
  }
  for (let i = K; i > 0; i--) {
    K_set *= i;
  }
  return N_set / K_set;
}

console.log(solution(input));
