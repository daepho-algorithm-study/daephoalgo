const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N) {
  // 메모이제이션 배열
  const memo = Array.from({length: N+1}, () => 0);

  // 초기값 설정 (memo[0]은 타일을 0개로 만들 수 있는 가짓수는 0이므로 그대로 냅둠)
  memo[1] = 1; // 1
  memo[2] = 2; // 00, 11

  // 점화식: f(n) = f(n-1) + f(n-2)
  // 타일을 n개로 만들 수 있는 가짓수: (n-1개일 때의 가짓수에다 마지막 1을 붙이는 경우) + (n-2개일 때의 가짓수에다 마지막에 00을 붙이는 경우)
  // 1  2  3  5  8  13  21...
  for (let i = 3; i <= N; i++) {
    memo[i] = (memo[i-1]+memo[i-2])%15746;  //수가 커지므로 미리 15746 나머지연산
  }


  return memo[N];
}

console.log(solution(input[0]));
