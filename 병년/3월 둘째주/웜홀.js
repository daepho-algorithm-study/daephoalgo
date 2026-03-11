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
  const T = Number(input[idx++]);

  for (let t = 0; t < T; t++) {
    const [N, M, W] = input[idx++].split(" ").map(Number);
    const dist = Array(N + 1).fill(0);
    const edges = [];
    for (let i = 0; i < M; i++) {
      const [S, E, T] = input[idx++].split(" ").map(Number);
      edges.push([S, E, T]);
      edges.push([E, S, T]);
    }

    for (let i = 0; i < W; i++) {
      const [S, E, T] = input[idx++].split(" ").map(Number);
      edges.push([S, E, -T]);
    }

    const bellman_ford = () => {
      for (let i = 0; i < N; i++) {
        for (const [s, e, t] of edges) {
          if (dist[e] > dist[s] + t) {
            dist[e] = dist[s] + t;

            if (i === N - 1) {
              return true;
            }
          }
        }
      }
      return false;
    };
    const flag = bellman_ford();
    console.log(flag ? "YES" : "NO");
  }
};
solution(input);
