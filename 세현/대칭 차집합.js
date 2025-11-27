const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  // .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0][0], M = input[0][1], A = new Set(input[1]), B = new Set(input[2]);
  let A_sym = A.size, B_sym = B.size;

  A.forEach((e) => {
    if (B.has(e)) {
      A_sym -= 1;
    }
  })

  B.forEach((e) => {
    if (A.has(e)) {
      B_sym -= 1;
    }
  })

  return A_sym + B_sym;
}

console.log(solution(input));
