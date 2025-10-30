const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => e.trim().split(" ").map((e) => Number(e)));

// console.log(input);

function solution(input) {
  const inp = input.slice(0, -1);
  let answer = [];
  //나누어 떨어지면 약수나 배수로 판별
  inp.forEach(([a, b]) => {
    if (a < b && b % a === 0) {
        answer.push("factor\n");
    } else if (b < a && a % b === 0) {
        answer.push("multiple\n");
    } else {
        answer.push("neither\n");
    }
  })

  return answer.join("").trim();
}

console.log(solution(input));
