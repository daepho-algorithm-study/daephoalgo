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
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }
  const visited = Array(N).fill(0);
  for (let i = 0; i < N; i++) {
    let cnt = 0;
    for (let j = 0; j < N; j++) {
      if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
        cnt++;
      }
    }
    visited[i] = cnt + 1;
  }
  console.log(visited.join(" "));
};
solution(input);
