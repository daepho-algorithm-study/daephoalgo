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
  const T = Number(input[idx++]);
  let answer = [];

  for (let t = 0; t < T; t++) {
    const n = Number(input[idx++]);
    const coords = [];
    for (let i = 0; i < n + 2; i++) {
      const [x, y] = input[idx++].split(" ").map(Number);
      coords.push([x, y]);
    }
    const visited = Array(n + 2).fill(false);
    const queue = [0];
    visited[0] = true;

    const bfs = () => {
      let flag = false;
      let head = 0;

      while (queue.length > head) {
        const cur = queue[head++];
        if (cur === n + 1) {
          flag = true;
          break;
        }
        for (let i = 0; i < n + 2; i++) {
          if (!visited[i]) {
            const next =
              Math.abs(coords[cur][0] - coords[i][0]) +
              Math.abs(coords[cur][1] - coords[i][1]);

            if (next <= 1000) {
              visited[i] = true;
              queue.push(i);
            }
          }
        }
      }
      answer.push(flag ? "happy" : "sad");
    };
    bfs();
  }
  console.log(answer.join("\n"));
};
solution(input);
