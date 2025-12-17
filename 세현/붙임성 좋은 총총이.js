const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" "));

// console.log(input);

function solution(input) {
  const rainbow = new Set(["ChongChong"])
  for (const [p1, p2] of input.slice(1)) {
    if (rainbow.has(p1) || rainbow.has(p2)) {
        rainbow.add(p1);
        rainbow.add(p2);
    }
  }
  return rainbow.size;
}

console.log(solution(input));
