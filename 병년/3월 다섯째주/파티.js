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
  let idx = 0;
  const [N, M, X] = input[idx++].split(" ").map(Number);
  const graph = Array.from({ length: N }, () => Array(N).fill(Infinity));
  for (let i = 0; i < N; i++) {
    graph[i][i] = 0;
  }

  for (let i = 0; i < M; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    graph[a - 1][b - 1] = c;
  }

  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
  let answer = 0;
  for (let i = 0; i < N; i++) {
    answer = Math.max(answer, graph[i][X - 1] + graph[X - 1][i]);
  }
  console.log(answer);
};
solution(input);
