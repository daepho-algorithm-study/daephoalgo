const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const inp = input.slice(0,-1);
  const answer = [];
  for (let i = 0; i < inp.length; i++) {
    const [a, b, c] = inp[i];
    let distinguish = "";
    const longest = Math.max(a, b, c)
    if ( longest >= (a+b+c-longest)) {
      distinguish = "Invalid"
    } else {
        if (a === b && b === c) distinguish = "Equilateral";
        else if (a === b || b === c || c === a) distinguish = "Isosceles";
        else distinguish = "Scalene";
    }
    answer.push(distinguish);
  }
  return answer.join('\n');
}

console.log(solution(input));
