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
  const [N, K] = input[0].split(" ").map(Number);
  const visited = Array.from({ length: 100001 }, () => false);

  const bfs = () => {
    let queue = [[N, 0]];
    visited[N] = true;

    while (queue.length > 0) {
      const [cur, time] = queue.shift();
      if (cur === K) return time;

      const next = [cur * 2, cur - 1, cur + 1];

      for (let i = 0; i < 3; i++) {
        if (0 <= next[i] && next[i] <= 100001 && !visited[next[i]]) {
          visited[next[i]] = true;
          if (next[i] === cur * 2) {
            queue.unshift([next[i], time]);
          }
          if (next[i] === cur - 1) {
            queue.push([next[i], time + 1]);
          }
          if (next[i] === cur + 1) {
            queue.push([next[i], time + 1]);
          }
        }
      }
    }
  };
  result = bfs();
  console.log(result);
};

solution(input);
