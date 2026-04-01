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
  const N = Number(input[0]);
  let degree = 120;
  const radians = degree * (Math.PI / 180);

  let answer = 0.5 * N * N * Math.sin(radians);
  console.log(answer);
};
solution(input);
