const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const [a, b, c] = input;
  const longest = Math.max(a, b, c);
  const twoline = a+b+c-longest;
  const dcr = twoline > longest ? longest : twoline - 1;

  return twoline + dcr;
}

console.log(solution(input));
