const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, stairs) {
  // 메모이제이션 배열
  const memo = Array.from({length: N}, () => 0);

  // 초기 값 설정
  memo[0] = stairs[0];
  memo[1] = memo[0] + stairs[1];
  // 3번째 칸 = 시작 지점에서 한칸 뛰고 두칸 뛰는 경우 or 시작지점에서 두칸 뛰고 한칸 뛰는 경우)
  memo[2] = Math.max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
  
  // 점화식: f(n) = Max ( f(n-3) + s(n-1) + s(n) ,   -> 이동 거리가 한 칸인 경우 그 이전은 무조건 2칸을 뛰었어야 함 그래서 세 칸 전 기록을 써야 함
  //                     f(n-2) + s(n)            ) -> 이동 거리가 두 칸인 경우 두 칸 전에 기록되어 있는 최댓값을 쓰면 됨
  for (let i = 3; i < N; i++) {
    memo[i] = Math.max(memo[i-3] + stairs[i-1] + stairs[i], memo[i-2] + stairs[i])
  }


  return memo[N-1];
}

console.log(solution(input[0], input.slice(1)));
