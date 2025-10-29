const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  let answer = "";
  let N = input[0];
  let i = 2;
  // 브루트포스 방식으로 해결
  while ( N > 1 ) {
    if (N % i === 0) {
      answer += `${i}\n`
      N /= i;
      continue;
    }
    i++;
  }

  return answer.trim();
}

console.log(solution(input));
