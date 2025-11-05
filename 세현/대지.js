const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0];
  let minx = 10000, miny = 10000;
  let maxx = -10000, maxy = -10000;
  for (let i = 1; i <= N; i++) {
    minx = Math.min(input[i][0], minx);
    miny = Math.min(input[i][1], miny);
    maxx = Math.max(input[i][0], maxx);
    maxy = Math.max(input[i][1], maxy);
  }

  return (maxx - minx) * (maxy - miny);
}

console.log(solution(input));
