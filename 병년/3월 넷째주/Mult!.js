const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");
const solution = (input) => {
  let idx = 0;
  const mults = [];
  const arr = [];
  const N = input[idx++];
  for (let i = 0; i < N; i++) {
    let num = Number(input[idx++]);
    arr.push(num);
  }
  let start = arr[0];
  for (let i = 1; i < N; i++) {
    let mult = arr[i] % start;
    if (arr[i] % start === 0) {
      mults.push(arr[i]);
      start = arr[i + 1];
      i++;
    }
  }
  for (let mult of mults) {
    console.log(mult);
  }
};
solution(input);
