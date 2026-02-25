const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, A, subset) {
  const S = Array.from({ length: N + 1 }, () => 0);

  // 누적합 배열 계산
  for (let i = 1; i <= N; i++) {
    S[i] = S[i - 1] + A[i - 1];
  }

  // 각 쿼리 구간 [start, end]의 합 출력
  for (let i = 0; i < M; i++) {
    const start = subset[i][0],
      end = subset[i][1];
    console.log(S[end] - S[start-1]);
  }

  return;
}

solution(input[0][0], input[0][1], input[1], input.slice(2));
