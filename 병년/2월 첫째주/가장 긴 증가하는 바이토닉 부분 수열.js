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
  const N = Number(input[0]);
  const arr = input[1].split(" ").map(Number);

  const dp = Array.from({ length: N }, () => 1);
  const r_dp = Array.from({ length: N }, () => 1);

  // 0번 인덱스부터 시작하는 LIS 구하기
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }
  // 뒤에서 부터 시작하는 LDS 구하기
  for (let k = N - 1; k >= 0; k--) {
    for (let l = N - 1; l > k; l--) {
      if (arr[k] > arr[l]) {
        r_dp[k] = Math.max(r_dp[k], r_dp[l] + 1);
      }
    }
  }
  let answer = 0;
  // 특정 인덱스를 기준으로 하는 바이토닉 수열 길이 구하기 특정 인덱스 기준이기 때문에 LIS, LDS
  // 둘다 해당 숫자를 쓰기 때문에 -1 해줌
  for (let i = 0; i < N; i++) {
    answer = Math.max(answer, dp[i] + r_dp[i] - 1);
  }
  console.log(answer);
};
solution(input);
