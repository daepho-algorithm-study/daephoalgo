const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, triangular) {
  // 메모이제이션 배열 생성
  const memo = Array.from({ length: N }, (_, i) => Array.from({ length: i + 1 }, () => 0));

  // 초기값 설정
  memo[0][0] = triangular[0][0];

  // 각 메모이제이션 칸에 현재 기록된 값과 직전 층 최댓값 + 현재 층 값 비교해서 큰 값을 기록해 주면 됨
  // 방향이 좌하단, 우하단 두가지 경우이기 때문에 거꾸로 올라가는 입장에서 봤을 때 좌상단 기록 값과 우상단 기록 값이 계속 변화함
  for (let i = 1; i < N; i++) {
    for (let j = 0; j < i; j++) {
      memo[i][j] = Math.max(memo[i][j], memo[i - 1][j] + triangular[i][j]);
      memo[i][j + 1] = Math.max(memo[i][j + 1], memo[i - 1][j] + triangular[i][j + 1]);
    }
  }

  return Math.max(...memo[N - 1]);
}

console.log(solution(input[0][0], input.slice(1)));
