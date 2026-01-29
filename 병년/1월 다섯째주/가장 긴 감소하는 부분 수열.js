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
  const arr = input[1].split(" ").map(Number);

  const dp = Array(1000).fill(1);

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {
      if (arr[i] < arr[j]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  console.log(Math.max(...dp));
};
solution(input);
