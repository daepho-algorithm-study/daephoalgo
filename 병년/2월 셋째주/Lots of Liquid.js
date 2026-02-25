const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = input[idx++];
  const arr = input[idx++].split(" ").map(Number);

  let preSum = 0;
  for (let i = 0; i < N; i++) {
    preSum += arr[i] ** 3;
  }

  console.log(Math.cbrt(preSum).toFixed(10));
};
solution(input);
