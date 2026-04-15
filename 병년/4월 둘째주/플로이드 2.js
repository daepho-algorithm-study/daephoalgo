const fs = require("fs");
const { get } = require("http");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const n = Number(input[idx++]);
  const m = Number(input[idx++]);
  const dist = Array.from({ length: n }, () => Array(n).fill(Infinity));
  const path = Array.from({ length: n }, () => Array(n).fill(-1));
  for (let i = 0; i < n; i++) {
    dist[i][i] = 0;
  }

  for (let i = 0; i < m; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    dist[a - 1][b - 1] = Math.min(dist[a - 1][b - 1], c);
    path[a - 1][b - 1] = b - 1;
  }

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] =  dist[i][k] + dist[k][j];
          path[i][j] = path[i][k];
        }
      }
    }
  }

  for (let i = 0; i < n; i++) {
  let row = "";
  for (let j = 0; j < n; j++) {
    row += (dist[i][j] === Infinity ? 0 : dist[i][j]) + " ";
  }
  console.log(row.trim());
}

  const getPath = (u, v) => {
    if (path[u][v] === -1) return [];

    const result = [u];
    while (u !== v) {
      u = path[u][v];
      result.push(u);
    }
    return result;
  };

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (i === j || path[i][j] === -1 || dist[i][j] === Infinity) {
        console.log(0);
        continue;
      }
      const result = getPath(i, j);
      console.log(result.length, result.map((v) => v + 1).join(" "));
    }
  }
};
solution(input);
