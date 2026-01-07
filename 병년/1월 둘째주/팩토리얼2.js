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
  let answer = 1;
  const fibo = (n) => {
    if (n === 0) {
      return;
    }
    answer = answer * n;
    fibo(n - 1);
  };
  fibo(N);
  console.log(answer);
};
solution(input);
