const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, curNum) {
  
  // 0! = 1이므로 기저조건으로 처리해야 함
  if (N <= 1) {
    return curNum;
  }
  const nextN = N-1
  return solution(nextN, N*curNum);
}

console.log(solution(input[0], 1));
