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
  const obj = {
    miss: 0,
    bad: 200,
    cool: 400,
    great: 600,
    perfect: 1000,
  };
  const [N, lv] = input[0].split(" ");

  let answer = N * obj[lv];
  console.log(answer);
};
solution(input);
