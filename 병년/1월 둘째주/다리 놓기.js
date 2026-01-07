const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const T = Number(input[0]);
  let idx = 1;

  for (let tc = 0; tc < T; tc++) {
    let [a, b] = input[idx++].split(" ").map(Number);

    const n = Math.max(a, b);
    const k = Math.min(a, b);

    const dp = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));

    for (let i = 0; i <= n; i++) {
      const upto = Math.min(i, k);
      for (let j = 0; j <= upto; j++) {
        if (j === 0 || j === i) dp[i][j] = 1;
        else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      }
    }

    console.log(dp[n][k]);
  }
};

solution(input);
