const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" "));
  }

  arr.sort((a, b) => a[0] - b[0]);
  for (let i = 0; i < arr.length; i++) {
    console.log(arr[i].join(" "));
  }
};
solution(input);
