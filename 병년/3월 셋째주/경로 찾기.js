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
  const dist = [];
  const check = Array.from({ length: N }, () => Array(N).fill(false));
  for (let i = 0; i < N; i++) {
    const row = input[idx++].split(" ").map(Number);
    dist.push(row);
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (dist[i][j] === 0) check[i][j] = false;
      else {
        check[i][j] = true;
      }
    }
  }
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (check[i][k] && check[k][j]) {
          check[i][j] = true;
        }
      }
    }
  }
  const answer = Array.from({ length: N }, () => Array(N).fill(N));
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (check[i][j] === false) answer[i][j] = 0;
      else {
        answer[i][j] = 1;
      }
    }
  }
  for (let i = 0; i < answer.length; i++) {
    console.log(answer[i].join(" "));
  }
};
solution(input);
