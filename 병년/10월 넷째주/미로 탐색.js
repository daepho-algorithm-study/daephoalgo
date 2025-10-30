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

const [N, M] = input[0].split(" ").map(Number);
const arr = input.slice(1).map((line) => line.split("").map(Number));

const solution = (arr) => {
  const visited = Array.from({ length: N }, () => Array(M).fill(false));

  const bfs = () => {
    visited[0][0] = true;
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];
    let queue = [[0, 0, 1]];

    while (queue.length > 0) {
      const size = queue.length;
      for (let i = 0; i < size; i++) {
        const [x, y, dist] = queue.shift();

        if (x === N - 1 && y === M - 1) return dist;

        for (let k = 0; k < 4; k++) {
          let nx = x + dx[k];
          let ny = y + dy[k];

          if (0 <= nx && nx < N && 0 <= ny < M) {
            if (arr[nx][ny] === 1 && !visited[nx][ny]) {
              visited[nx][ny] = true;
              queue.push([nx, ny, dist + 1]);
            }
          }
        }
      }
    }
  };

  console.log(bfs());
};

solution(arr);
