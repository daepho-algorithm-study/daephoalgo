const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("/n");

const solution = (input) => {
  return input * 4000;
};

const result = solution(Number(input[0]));
console.log(result);
