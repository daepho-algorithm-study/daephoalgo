const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

//console.log(input);

function solution(input) {
  const lng = input[0][0];
  const k = input[0][1];
  
  const numbers = input[1];
  for (let i = 0; i < lng - 1; i++) {
    for (let j = 0; j < lng - 1; j++) {
        if (numbers[j] > numbers[j+1]) {
            const temp = numbers[j];
            numbers[j] = numbers[j+1];
            numbers[j+1] = temp;
        }
    }
  }

  return numbers[lng-k];
}

console.log(solution(input));
