const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [N, b] = input[0].split(" ").map(Number);
  console.log(N <= 2 ** (b + 1) - 1 ? "yes" : "no");
};
solution(input);
