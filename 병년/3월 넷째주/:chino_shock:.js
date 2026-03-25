const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let str = input[0].split("");
  let colon = 0;
  let underbar = 0;

  for (let ch of str) {
    if (ch === ":") {
      colon++;
    } else if (ch === "_") {
      underbar++;
    }
  }
  console.log(str.length + colon + underbar * 5);
};
solution(input);
