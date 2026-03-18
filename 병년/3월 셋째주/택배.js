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
  const dist = Array.from({ length: N }, () => Array(N).fill(Infinity));
  const next = Array.from({ length: N }, () => Array(N).fill(-1));
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      dist[i][i] = 0;
      next[i][j] = j;
    }
  }

  for (let i = 0; i < M; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = Math.min(dist[a - 1][b - 1], c);
    dist[b - 1][a - 1] = Math.min(dist[b - 1][a - 1], c);
    next[a - 1][b - 1] = b - 1;
    next[b - 1][a - 1] = a - 1;
  }

  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  let answer = "";
  for (let i = 0; i < N; i++) {
    let row = [];
    for (let j = 0; j < N; j++) {
      if (i === j) row.push("-");
      else row.push(next[i][j] + 1);
    }
    answer += row.join(" ") + "\n";
  }
  console.log(answer.trim());
};
solution(input);
