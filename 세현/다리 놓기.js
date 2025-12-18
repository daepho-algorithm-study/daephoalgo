const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", 'utf-8')
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const T = input[0][0];
  for (let i = 1; i <= T; i++) {
    const N = BigInt(input[i][0]), M = BigInt(input[i][1]);
    let ans = 1n; // Bigint 1
    for (let i = 1n; i <= N; i++) {
        ans = ans * (M-i+1n) / i;
    }
    console.log(ans.toString());
  }
}

solution(input);
