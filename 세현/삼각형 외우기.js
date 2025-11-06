const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const [a, b, c] = input;
  const degree = a+b+c;
  if (degree !== 180) {
    return "Error"
  }

  if (a === b && b === c) return "Equilateral";
  else if (a === b || b === c || c === a) return "Isosceles";
  else return "Scalene";

}

console.log(solution(input));
