const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const x = Number(input[0]);

  const solve = (n) => {
    if (n < 100) return true;
    const digit = n.toString().split("").map(Number);
    const diff = digit[1] - digit[0];

    for (let i = 2; i < digit.length; i++) {
      if (digit[i] - digit[i - 1] !== diff) return false;
    }
    return true;
  };
  result = 0;
  for (let i = 1; i < x + 1; i++) {
    if (solve(i)) result++;
  }
  console.log(result);
};
solution(input);
