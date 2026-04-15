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
  const [N, M, K] = input[idx++].split(" ").map(Number);
  const graph = [];
  for (let i = 0; i < N; i++) {
    graph.push(input[idx++].split("").map(Number));
  }

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const dist = Array.from({ length: N }, () =>
    Array.from({ length: M }, () => Array(K + 1).fill(false)),
  );

  q = [];
  dist[0][0][0] = 1;
  q.push([0, 0, 0, 1]);

  const bfs = () => {
    let head = 0;
    while (q.length > head) {
      let [x, y, broken, depth] = q[head++];
      if (x === N - 1 && y === M - 1) {
        return depth;
      }

      for (let k = 0; k < 4; k++) {
        let nx = x + dx[k];
        let ny = y + dy[k];

        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
          if (graph[nx][ny] === 0) {
            if (dist[nx][ny][broken] === false) {
              dist[nx][ny][broken] = true;
              q.push([nx, ny, broken, depth + 1]);
            }
          } else if (graph[nx][ny] === 1 && broken < K) {
            let newBroken = broken + 1;
            if (dist[nx][ny][newBroken] === false) {
              dist[nx][ny][newBroken] = true;
              q.push([nx, ny, newBroken, depth + 1]);
            }
          }
        }
      }
    }
    return -1;
  };
  let result = bfs();
  console.log(result);
};
solution(input);