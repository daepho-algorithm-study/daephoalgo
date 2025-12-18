const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", 'utf-8')
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  let cnt = 0;
  const gomha = new Set;
  for (nik of input.slice(1)) {
    if (nik === 'ENTER') {
        gomha.clear();
    } else {
        if (!gomha.has(nik)) {
            gomha.add(nik);
            cnt++;
        }
    }
  }
  return cnt;
}

console.log(solution(input));
