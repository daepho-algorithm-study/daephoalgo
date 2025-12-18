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
  let idx = 0;
  const [N, K] = input[idx++].split(" ").map(Number);

  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }
  const [S, X, Y] = input[idx++].split(" ").map(Number);

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const bfs = () => {
    const queue = [];

    let head = 0;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (arr[i][j] !== 0) {
          queue.push([arr[i][j], i, j, 0]);
        }
      }
    }

    queue.sort((a, b) => a[0] - b[0]);

    while (queue.length > head) {
      const [virus, x, y, time] = queue[head++];
      if (time === S) break;
      for (let k = 0; k < 4; k++) {
        let nx = x + dx[k];
        let ny = y + dy[k];

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
          if (arr[nx][ny] === 0) {
            arr[nx][ny] = virus;
            queue.push([virus, nx, ny, time + 1]);
          }
        }
      }
    }
  };
  bfs();
  console.log(arr[X - 1][Y - 1] !== 0 ? arr[X - 1][Y - 1] : 0);
};
solution(input);
