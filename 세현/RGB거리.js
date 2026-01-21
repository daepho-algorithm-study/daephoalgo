const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, RGB) {

  // 메모이제이션 배열 (N 행 3열 형태)
  const memo = Array.from({length: N}, () =>
    Array.from({length: 3}, () => 0)
  );

  // 0 열은 해당 행 번째 집에 **빨간 색**을 칠하는 경우
  // 1 열은 해당 행 번째 집에 **초록 색**을 칠하는 경우
  // 2 열은 해당 행 번째 집에 **파란 색**을 칠하는 경우
  memo[0][0] = RGB[0][0];
  memo[0][1] = RGB[0][1];
  memo[0][2] = RGB[0][2];
  
  // 해당 행에서 칠하는 색은 이전에 칠했던 색과 같을 수 없음
  // 즉, 그 행의 열과 이전의 열은 무조건 달라야 함
  // 열은 3개이므로 하나를 뺀 나머지 2개의 열 중 최댓값을 더해주면 됨
  for (let i = 1; i < N; i++) {
      memo[i][0] = RGB[i][0] + Math.min(memo[i-1][1], memo[i-1][2]);
      
      memo[i][1] = RGB[i][1] + Math.min(memo[i-1][0], memo[i-1][2]);
      
      memo[i][2] = RGB[i][2] + Math.min(memo[i-1][0], memo[i-1][1]);
      
    }

    // 핵심
    // 내가 원하는 것은 각 단계마다 얼마나 최소 비용으로 칠했는가를 기록하는 것
    // 해당 집을 빨강, 초록, 파랑으로 칠했을 때의 경우를 모두 기록하는 것 <---- 이거 중요
    // 이룰 기록해 둠으로써 직전 단계에서 해당 집을 각 색으로 칠했을때의 최솟값을 가지고 있으니까 다음 단계에서 가능한 값 중 최솟값을 더해주면 끝임

  return Math.min(...memo[N-1]);
}

console.log(solution(input[0][0], input.slice(1)));
