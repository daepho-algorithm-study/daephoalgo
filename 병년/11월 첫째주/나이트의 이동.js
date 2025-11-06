const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const T = input[idx++];
  const dx = [-2, -1, 1, 2, 2, 1, -1, -2];
  const dy = [1, 2, 2, 1, -1, -2, -2, -1];
  const results = [];

  for (let tc = 0; tc < T; tc++) {
    const N = Number(input[idx++]); // 체스판 한 변 길이
    const [startX, startY] = input[idx++].split(" ").map(Number);
    const [endX, endY] = input[idx++].split(" ").map(Number);
    const visited = Array.from({ length: N }, () => Array(N).fill(false));

    const bfs = () => {
      let queue = [[startX, startY, 0]];

      visited[startX][startY] = true;

      let head = 0;
      while (queue.length > head) {
        const [x, y, cnt] = queue[head++];

        if (x === endX && y === endY) return cnt;

        for (let k = 0; k < 8; k++) {
          let nx = x + dx[k];
          let ny = y + dy[k];

          if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
            visited[nx][ny] = true;
            queue.push([nx, ny, cnt + 1]);
          }
        }
      }
    };
    results.push(bfs());
  }
  console.log(results.join("\n"));
};
solution(input);
