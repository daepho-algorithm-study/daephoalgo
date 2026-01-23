const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [M, N] = input[0].split(" ").map(Number);
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const visited = Array.from({ length: N }, () => Array(M).fill(0));

  const arr = [];
  for (let i = 1; i <= N; i++) {
    arr.push(input[i].split(""));
  }

  const dfs = (x, y, color) => {
    visited[x][y] = 1;
    let cnt = 1;
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (!visited[nx][ny] && arr[nx][ny] === color) {
          cnt += dfs(nx, ny, color);
        }
      }
    }

    return cnt;
  };
  //   const bfs = (x, y, color) => {
  //     let head = 0;
  //     let queue = [[x, y]];

  //     visited[x][y] = true;
  //     let cnt = 1;

  //     while (head < queue.length) {
  //       const [nx, ny] = queue[head++];

  //       for (let k = 0; k < 4; k++) {
  //         const nnx = nx + dx[k];
  //         const nny = ny + dy[k];

  //         if (0 <= nnx && nnx < N && 0 <= nny && nny < M) {
  //           if (!visited[nnx][nny] && arr[nnx][nny] === color) {
  //             visited[nnx][nny] = true;
  //             queue.push([nnx, nny]);
  //             cnt++;
  //           }
  //         }
  //       }
  //     }
  //     return cnt;
  //   };

  let w_total = 0;
  let b_total = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (visited[i][j] === 0) {
        const color = arr[i][j];
        const size = dfs(i, j, color);
        if (color === "W") w_total += size * size;
        else b_total += size * size;
      }
    }
  }

  console.log(w_total, b_total);
};

solution(input);
