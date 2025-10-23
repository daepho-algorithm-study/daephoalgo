const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {

  // 점화식 찾는 문제
  // 점의 개수는 4, 9, 25, 81, 289 ... 순으로 늘어남
  // 즉, 2*2, 3*3, 5*5, 9*9, 17*17 ... 와 상동함
  // (한 변의 점 개수)의 간격을 찾을 수 있음 -> f(n) = f(n-1) + 2^(n-1)

  let answer = 0;
  const N = input[0];
  let oneLine = 2;
  for (let i = 0; i < N; i++) {
    oneLine += 2**i;
  }
  answer = oneLine * oneLine;
  return answer;
}

console.log(solution(input));
