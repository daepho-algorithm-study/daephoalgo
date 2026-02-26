const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);

  const arr = input[idx++].split(" ").map(Number);
  let cnt = 0;
  let sum = 0;

  for (let num of arr) {
    sum += num;
    if (sum < 0) sum = 0;
    if (sum >= M) cnt++;
  }
  console.log(cnt);
};

solution(input);
