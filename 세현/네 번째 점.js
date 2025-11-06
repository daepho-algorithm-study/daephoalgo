const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  let x = [];
  let y = [];

  for (let i = 0; i < 3; i++) {
    if (x.includes(input[i][0])) {
        const idx = x.indexOf(input[i][0]);
        x.splice(idx, 1);
    } else {
        x.push(input[i][0])
    }
    if (y.includes(input[i][1])) {
        const idx = y.indexOf(input[i][1]);
        y.splice(idx, 1);

    } else {
        y.push(input[i][1])
    }
  }

  return x[0] + " " + y[0];
}

console.log(solution(input));
