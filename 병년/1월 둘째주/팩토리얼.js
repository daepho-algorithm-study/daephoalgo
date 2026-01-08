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
  let answer = 1;
  const recur = (n) => {
    if (n > N) {
      return;
    }
    answer = answer * n;
    recur(n + 1);
  };
  recur(1);
  console.log(answer);
};

solution(input);
