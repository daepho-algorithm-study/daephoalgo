const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [n, k] = input[idx++].split(" ").map(Number);
  const dist = Array.from({ length: n }, () => Array(n).fill(Infinity));

  for (let i = 0; i < n; i++) {
    dist[i][i] = 0;
  }

  for (let i = 0; i < k; i++) {
    const [a, b] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = 1;
  }

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  const s = Number(input[idx++]);
  for (let i = 0; i < s; i++) {
    const [a, b] = input[idx++].split(" ").map(Number);
    if (dist[a - 1][b - 1] !== Infinity) console.log(-1);
    else if (dist[b - 1][a - 1] !== Infinity) console.log(1);
    else console.log(0);
  }
};
solution(input);
