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
  const N = Number(input[0]);

  const solve = (num) => {
    let result = 0;
    let arr = num.toString().split("").map(Number);
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
      sum += arr[i];
    }
    result = num + sum;
    return result;
  };
  let solved = 0;
  let result = 0;
  for (let i = 1; i < 1000000; i++) {
    solved = solve(i);
    if (solved === N) {
      result = i;
      break;
    }
  }
  console.log(result);
};
solution(input);
