const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(n, fn1, fn2, curN) {
  if (n === curN) {
    return fn2;
  } else if (n === 0) {
    return 0;
  }

  return solution(n, fn2, fn1+fn2, curN+1);
}

console.log(solution(input[0], 0 , 1, 1));
