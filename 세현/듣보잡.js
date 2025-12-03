const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const fst_line = input[0].split(" ").map(Number)
  const N = fst_line[0]

  const named = new Set(input.slice(1, N+1));
  const looked = new Set(input.slice(N+1))
  
  cnt = 0
  const answer = [];

  named.forEach((e) => {
    if (looked.has(e)) {
        answer.push(e);
        cnt += 1;
    }
  })
  if (cnt === 0) {
    return 0
  }
  answer.sort();
  return [cnt, answer.join('\n')].join('\n');
}

console.log(solution(input));
