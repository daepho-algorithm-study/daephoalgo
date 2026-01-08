const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);
  total = 0;
  if (N === 0 || N === 1) return N;
  const fibo = (depth, before, n) => {
    if (depth === N) {
      total = n;
      return;
    }
    now = before + n;
    fibo(depth + 1, n, now);
  };
  fibo(1, 0, 1);
  return total;
};
let answer = solution(input);
console.log(answer);
