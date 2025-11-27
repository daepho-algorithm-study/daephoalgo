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
  const [S] = input;
  const s_set = new Set();

  for (let i = 0; i < S.length; i++) {
    for (let j = i+1; j < S.length+1; j++) {
        s_set.add(S.slice(i, j));
    }
  }

  return s_set.size;
}

console.log(solution(input));
