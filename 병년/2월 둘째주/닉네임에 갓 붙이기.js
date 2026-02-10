const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);
  for (let i = 1; i < N + 1; i++) {
    const arr = input[i].split(" ");
    arr[0] = "god";
    console.log(arr.join(""));
  }
};
solution(input);
