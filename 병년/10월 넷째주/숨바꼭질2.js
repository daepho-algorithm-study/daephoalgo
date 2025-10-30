const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [N, K] = input[0].split(" ").map(Number);

  const visited = Array.from({ length: 100001 }, () => -1);

  let minTime = Infinity;
  let cnt = 0;
  if (N === K) {
    console.log(0);
    console.log(1);
    return;
  }
  const bfs = () => {
    let head = 0;
    let queue = [[N]];

    visited[N] = 0;

    while (queue.length > head) {
      let [cur] = queue[head++];

      if (cur === K) {
        minTime = visited[cur];
        cnt++;
        continue;
      }

      let next = [cur + 1, cur - 1, cur * 2];

      for (let i = 0; i < 3; i++) {
        if (0 <= next[i] && next[i] <= 100000) {
          if (visited[next[i]] === -1) {
            visited[next[i]] = visited[cur] + 1;
            queue.push([next[i]]);
          } else if (visited[next[i]] === visited[cur] + 1) {
            queue.push([next[i]]);
          }
        }
      }
    }
  };
  bfs();
  console.log(minTime);
  console.log(cnt);
};
solution(input);
