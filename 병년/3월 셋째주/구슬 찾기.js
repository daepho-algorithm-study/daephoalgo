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
  for (let i = 0; i < N; i++) {
    dist[i][i] = 0;
  }
  for (let i = 0; i < M; i++) {
    const [a, b] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = 1;
  }
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  let answer = 0;
  let mid = (N + 1) / 2;
  for (let i = 0; i < N; i++) {
    let high = 0;
    let low = 0;
    for (let j = 0; j < N; j++) {
      if (dist[i][j] !== Infinity && dist[i][j] > 0) high++;
      else if (dist[j][i] !== Infinity && dist[j][i] > 0) low++;
    }
    if (high >= mid || low >= mid) answer++;
  }
  console.log(answer);
};
solution(input);
