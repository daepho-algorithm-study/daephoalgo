const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("/n");

const solution = (input) => {
  const [n1, n2, n3] = input[0].split(" ").map(Number);
  let sum = (n1 + 1) * (n2 + 1);
  let result = Math.floor(sum / (n3 + 1));
  return result;
};
let result = solution(input) - 1;
console.log(result);
