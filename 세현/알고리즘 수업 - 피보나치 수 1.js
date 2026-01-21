const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(n) {
  let fibcnt = 0;       // 재귀 횟수
  let fibonaccicnt = 0; // DP 횟수

  const fib = (n) => {
      if (n === 1 || n === 2) {
        fibcnt++;               // 재귀가 끝날 떄 카운트 횟수 증가
        return 1;
    }

    return (fib(n-1) + fib(n-2));
  }

  const fibonacci = (n) => {
    const f = Array.from({length: n}, () => 0);
    f[0] = 1;
    f[1] = 1;
    for (let i = 2; i < n; i++) {
        fibonaccicnt++;           // 반복 기록 될때 카운트 횟수 증가
        f[i] = f[i-1] + f[i-2];
    }
    return f[n]
  }
  fib(n);
  fibonacci(n);

  return `${fibcnt} ${fibonaccicnt}`;
}

console.log(solution(input[0]));
