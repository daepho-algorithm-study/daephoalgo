const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);
  const arr = input[1]
    .split(" ")
    .map(Number)
    .sort((a, b) => a - b);

  // 누적합
  let preSum = 0;
  // 결과
  let answer = 0;
  for (let i = 0; i < N; i++) {
    // 누적합 갱신
    preSum += arr[i];
    // 결과값에 누적합 합산
    answer += preSum;
  }
  console.log(answer);
};
solution(input);
