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

  for (let i = 0; i < M; i++) {
    let [a, b, c] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = Math.min(dist[a - 1][b - 1], c);
  }
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  let answer = Infinity;
  for (let i = 0; i < dist.length; i++) {
    if (answer > dist[i][i]) {
      answer = dist[i][i];
    }
  }
  console.log(answer === Infinity ? -1 : answer);
};
solution(input);
