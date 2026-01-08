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
  const arr = input.map(Number);
  for (let i = 0; i < arr.length; i++) {
    const cantor = (n) => {
      if (n === 1) return "-";
      else {
        const left = cantor(Math.floor(n / 3));
        const right = " ".repeat(Math.floor(n / 3));
        return left + right + left;
      }
    };
    let result = cantor(3 ** arr[i]);
    console.log(result);
  }
};
solution(input);
