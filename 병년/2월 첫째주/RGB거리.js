const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }

  // RGB 거리를 가지는 N 개의 집 배열 생성
  const dp = Array.from({ length: N }, () => Array(3).fill(0));

  // 첫 번째 집에 R, G, B 할당
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][1];
  dp[0][2] = arr[0][2];

  for (let i = 1; i < N; i++) {
    //
    dp[i][0] = arr[i][0] + Math.min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = arr[i][1] + Math.min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = arr[i][2] + Math.min(dp[i - 1][0], dp[i - 1][1]);
  }
  console.log(dp);
  console.log(Math.min(...dp[N - 1]));
};
solution(input);
