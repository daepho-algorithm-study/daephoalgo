const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, K, tem) {
  let mxTem = -Infinity;

  // 누적합 배열
  const S = Array.from({ length: N + 1 }, () => 0);

  // 누적합 계산
  for (let i = 1; i <= N; i++) {
    S[i] = S[i - 1] + tem[i - 1];
  }

  // K 구간 합 최댓값 탐색
  for (let i = 1; i + K - 1 <= N; i++) {
    if (mxTem < S[i + K - 1] - S[i - 1]) {
      mxTem = S[i + K - 1] - S[i - 1];
    }
  }

  return mxTem;
}

console.log(solution(input[0][0], input[0][1], input[1]));
