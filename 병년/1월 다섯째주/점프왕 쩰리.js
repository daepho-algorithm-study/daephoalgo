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
  const N = Number(input[0]);
  const arr = [];

  for (let i = 1; i <= N; i++) {
    arr.push(input[i].split(" ").map(Number));
  }

  const visited = Array.from({ length: N }, () => Array(N).fill(false));

  const dfs = (x, y) => {
    visited[x][y] = true;
    const jump = arr[x][y];
    if (x === N - 1 && y === N - 1) {
      return true;
    }

    if (jump === 0) return false;

    const nx1 = x + jump;
    const ny1 = y;
    if (0 <= nx1 && nx1 < N && !visited[nx1][ny1]) {
      if (dfs(nx1, ny1)) return true;
    }

    const nx2 = x;
    const ny2 = y + jump;

    if (0 <= ny2 && ny2 < N && !visited[nx2][ny2]) {
      if (dfs(nx2, ny2)) return true;
    }

    return false;
  };

  let answer = dfs(0, 0);
  console.log(answer ? "HaruHaru" : "Hing");
};

solution(input);
