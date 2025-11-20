const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

//console.log(input);

function solution(input) {
  const numbers = input;
  const avg = input.reduce((acc, cur) => acc + cur, 0)/5
  for (let i = 0; i < 4; i++) {
    for (let j = 0; j < 4; j++) {
        if (numbers[j] > numbers[j+1]) {
            const temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp;
        }
    }
  }

  return [avg, numbers[2]];
}

console.log(solution(input).join('\n'));
