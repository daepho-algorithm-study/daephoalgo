const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const fst_line = input[0].split(" ").map(Number)
  const N = fst_line[0], M = fst_line[1];

  const S = new Set(input.slice(1, N+1));
  const check = input.slice(N+1);
  let cnt = 0;
  check.forEach((e) => {
    if (S.has(e)) cnt += 1;
  })
  return cnt;
}

console.log(solution(input));
