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
  const N = Number(input[0]);
  // dp 배열 1로 초기화 하나의 숫자를 뽑는 것도 수열이기 때문에
  const dp = Array(1000).fill(1);

  const arr = input[1].split(" ").map(Number);
  // 현재 값과 그 이전 값 비교
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {
        // 현재 값이 그 이전의 값과 비교해서 더 크다면
      if (arr[i] > arr[j]) {
        // 현재 값을 이전 수열에 넣어본 값과 현재 값의 부분 수열의 개수를 비교해서
        // 더 큰 값 할당
        // 그 이유는 예를 들어 A = {10, 20, 30, 50} 라고 가정 할 때
        // for 문이 돌아갈 때 dp[0] = 1 dp[1] = 1, dp[0] + 1 = 2 
        // dp[2] = dp[2] = 1, dp[0] + 1 = 2, dp[2] = 2, dp[1] + 1 = 3, dp[2] = 3
        // dp[3] = dp[3] = 1, dp[0] + 1 = 2, dp[3] = 2, dp[1] + 2 = 2, dp[3] = 2, dp[2] + 1 = dp[3] = 4

        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }
  console.log(Math.max(...dp));
};

solution(input);
