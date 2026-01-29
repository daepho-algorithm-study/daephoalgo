const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }

  arr.sort((a, b) => a[0] - b[0]);

  const dp = Array(N).fill(1);

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {
      if (arr[i][1] > arr[j][1]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  console.log(N - Math.max(...dp));
};
solution(input);
