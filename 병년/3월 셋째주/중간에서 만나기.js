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
    const [a, b, c] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = Math.min(dist[a - 1][b - 1], c);
  }

  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  const c = Number(input[idx++]);
  const friends = input[idx++].split(" ").map(Number);

  const results = Array(N).fill(-1);
  for (let i = 0; i < N; i++) {
    let max = -1;
    for (let f of friends) {
      if (dist[i][f - 1] === Infinity || dist[f - 1][i] === Infinity) break;
      max = Math.max(max, dist[f - 1][i] + dist[i][f - 1]);
    }
    results[i] = max;
  }
  let min = Math.min(...results);
  let answers = [];
  for (let i = 0; i < results.length; i++) {
    if (results[i] === min) answers.push(i + 1);
  }
  console.log(answers.join(" "));
};
solution(input);
