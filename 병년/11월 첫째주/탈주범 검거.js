const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const T = Number(input[idx++]);
  const tunnel = {
    0: [],
    1: [
      [-1, 0],
      [1, 0],
      [0, -1],
      [0, 1],
    ], // 상하좌우
    2: [
      [-1, 0],
      [1, 0],
    ], // 상하
    3: [
      [0, -1],
      [0, 1],
    ], // 좌우
    4: [
      [-1, 0],
      [0, 1],
    ], // 상우
    5: [
      [1, 0],
      [0, 1],
    ], // 하우
    6: [
      [1, 0],
      [0, -1],
    ], // 하좌
    7: [
      [-1, 0],
      [0, -1],
    ], // 상좌
  };

  for (let tc = 0; tc < T; tc++) {
    const [N, M, R, C, L] = input[idx++].split(" ").map(Number);

    const arr = [];
    for (let i = 0; i < N; i++) {
      arr.push(input[idx++].split(" ").map(Number));
    }

    const bfs = (r, c) => {
      const visited = Array.from({ length: N }, () => Array(M).fill(0));
      visited[r][c] = 1;

      const queue = [[r, c]];
      let head = 0;
      let cnt = 1;

      while (queue.length > head) {
        const [x, y] = queue[head++];

        if (visited[x][y] >= L) continue;

        for (let [dx, dy] of tunnel[arr[x][y]]) {
          const nr = x + dx;
          const nc = y + dy;

          if (0 <= nr && nr < N && 0 <= nc && nc < M) {
            if (!visited[nr][nc] && arr[nr][nc] !== 0) {
              const canConnect = tunnel[arr[nr][nc]].some(([nx, ny]) => nx === -dx && ny === -dy);

              if (canConnect) {
                visited[nr][nc] = visited[x][y] + 1;
                queue.push([nr, nc]);
                cnt += 1;
              }
            }
          }
        }
      }

      return cnt;
    };

    let cnt = bfs(R, C);
    console.log(cnt);
  }
};

solution(input);
