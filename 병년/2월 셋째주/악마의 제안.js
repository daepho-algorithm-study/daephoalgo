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
  .split(" ");

const solution = (input) => {
  let K = BigInt(input[0]);
  let N = BigInt(input[1]);
  if (N === 1n) {
    console.log(-1);
    return;
  }

  const answer = (K * N + (N - 2n)) / (N - 1n);
  console.log(answer.toString());
};
solution(input);
