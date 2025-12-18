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
  const dx = [-1, 1, 0, 0, -1, 1, 1, -1];
  const dy = [0, 0, -1, 1, -1, -1, 1, 1];
  const [N, M] = input[0].split(" ").map(Number);
  const arr = input.slice(1).map((line) => line.split(" ").map(Number));

  const bfs = () => {
    let queue = [];
    let head = 0;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        if (arr[i][j] === 1) queue.push([i, j]);
      }
    }

    while (queue.length > head) {
      const [x, y] = queue[head++];
      for (let k = 0; k < 8; k++) {
        let nx = x + dx[k];
        let ny = y + dy[k];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
          if (arr[nx][ny] === 0) {
            arr[nx][ny] = arr[x][y] + 1;
            queue.push([nx, ny]);
          }
        }
      }
    }
  };

  let mx = 0;
  bfs();

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      mx = Math.max(mx, arr[i][j]);
    }
  }
  console.log(mx - 1);
};
solution(input);
